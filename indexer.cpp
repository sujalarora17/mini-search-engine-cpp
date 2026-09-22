#include "Indexer.h"
#include "Tokenizer.h"
#include <iostream>

using namespace std;

void Indexer::buildIndex(const vector<string>& documents) {
    for (int docID = 0; docID < documents.size(); docID++) {
        vector<string> tokens = Tokenizer::tokenize(documents[docID]);

        for (int pos = 0; pos < tokens.size(); pos++) {
            string word = tokens[pos];
            invertedIndex[word][docID+1].push_back(pos);
        }
    }
}

void Indexer::displayIndex() const {
    cout << "\nPositional Inverted Index:\n\n";

    for (const auto& wordEntry : invertedIndex) {
        cout << wordEntry.first << " -> ";

        for (const auto& docEntry : wordEntry.second) {
            cout << "(Doc " << docEntry.first << ": ";
            
            for (int pos : docEntry.second) {
                cout << pos << " ";
            }

            cout << ") ";
        }

        cout << endl;
    }
}

set<int> Indexer::getDocuments(const string& word) const {
    set<int> docs;

    if (!invertedIndex.count(word))
    { 
        return docs;
    }

    for (const auto& entry : invertedIndex.at(word)) {
        docs.insert(entry.first);
    }

    return docs;
}

vector<int> Indexer::phraseSearch(const string& w1, const string& w2) const
{
    vector<int> result;

    if (!invertedIndex.count(w1) || !invertedIndex.count(w2)){
        return result;
    }

    const auto& docs1 = invertedIndex.at(w1);
    const auto& docs2 = invertedIndex.at(w2);

    for (auto& [docID, pos1] : docs1) {
        if (!docs2.count(docID)) {
            continue;
        }

        const vector<int>& pos2 = docs2.at(docID);

        for (int p1 : pos1) {
            for (int p2 : pos2) {
                if (p2 == p1 + 1) {
                    result.push_back(docID);
                    break;
                }
            }
        }
    }

    return result;
}