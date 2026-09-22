#include "SearchEngine.h"
#include <iostream>
#include <fstream>
#include "Tokenizer.h"
#include <algorithm>
#include <filesystem>
#include <cctype>

using namespace std;
namespace fs = filesystem;

void SearchEngine::loadDocuments(const string& filename)
{
    ifstream file(filename);

    if (!file)
    {
        cout << "Error opening file.\n";
        return;
    }

    string line;

    while (getline(file, line)) {
        documents.push_back(line);
    }

    file.close();

    cout << "Documents loaded successfully.\n";
}

void SearchEngine::displayDocuments() const{
    cout << "\nDocuments in the system: \n";

    for (int i = 0; i < documents.size(); i++) {
        cout << "Doc" << i + 1 << ": " << documents[i] << endl;
    }
}

int SearchEngine::getDocumentCount() const{
    return documents.size();
}

void SearchEngine::buildIndex() {
    indexer.buildIndex(documents);
}

void SearchEngine::displayIndex() const 
{
    indexer.displayIndex();
}

void SearchEngine::searchQuery(const string& query) const {
    QueryEngine qe(indexer);

    set<int> results = qe.search(query);

    cout << "\nSearch Results:\n";

    if (results.empty())
    {
        cout << "No documents found.\n";
        return;
    }

    for (int id : results) {
        cout << "Doc " << id << ": "
             << documents[id-1] << endl;
    }
}

void SearchEngine::rankedSearch(const string& word) const {
    set<int> docs = indexer.getDocuments(word);

    vector<pair<int, int>> scores;

    for (int id : docs) {
        vector<string> tokens = Tokenizer::tokenize(documents[id-1]);

        int count = 0;
        
        for (const string& t : tokens) 
        {
            if (t == word) 
                count++;
        }
        scores.push_back({id,count});
    }

    sort(scores.begin(), scores.end(), 
        [](const pair<int,int>& a, const pair<int,int>& b)
    {
        return a.second > b.second;
    });

    cout << "\nRanked Results:\n";

    for (auto &p : scores) {
        cout << "Doc " << p.first
            << " (score " << p.second << "): "
            << documents[p.first-1] << endl;
    }
}

void SearchEngine::tfidfSearch(const string& word) const {
    set<int> docs = indexer.getDocuments(word);

    int N = documents.size();
    int DF = docs.size();

    if (DF == 0) {
        cout << "No documents found.\n";
        return;
    }

    double idf = long((double)N / DF);

    vector<pair<int,double>> scores;

    for (int id : docs) {
        vector<string> tokens = Tokenizer::tokenize(documents[id-1]);

        int tf = 0;

        for (const string &t : tokens) {
            if (t == word) 
                tf++;
        }
        double score = tf * idf;

        scores.push_back({id, score});
    }

    sort(scores.begin(), scores.end(),[](auto &a, auto &b) {
        return a.second > b.second;
    });

    cout << "\nTF-IDF Ranked Results:\n";

    for (auto &p : scores) {
        cout << "Doc " << p.first 
            << " (score " << p.second << "): "
            << documents[p.first-1] << endl;
    }
}

void SearchEngine::phraseSearch(const string& phrase) const {
    vector<string> words = Tokenizer::tokenize(phrase);

    if (words.size() != 2) {
        cout << "Only two-word phrases supported.\n";
        return;
    }

    vector<int> docs = indexer.phraseSearch(words[0], words[1]);

    if (docs.empty()) {
        cout << "No phrase matches found.\n";
        return;
    }

    cout << "\nPhrase Search Results:\n";

    for (int id : docs) {
        cout << "Doc " << id << ": "
             << documents[id-1] << endl;
    }
}

void SearchEngine::loadDocumentsFromDirectory(const string& folder) {
    documents.clear();

    for (const auto& entry : fs::directory_iterator(folder)) {
        if (entry.path().extension() == ".txt") {
            ifstream file(entry.path());

            string line;
            string content;

            while (getline(file, line)) {
                content += line + " ";
            }

            documents.push_back(content);

            file.close();
        }
    }

    cout << documents.size() << " documents loaded from directory.\n";
}

string toLower(string text) {
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    return text;
}