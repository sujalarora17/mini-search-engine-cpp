#include <iostream>
#include "SearchEngine.h"
#include "Tokenizer.h"
#include "Indexer.h"
#include <cctype>
#include <algorithm>

using namespace std;

int main() {

    SearchEngine engine;

    engine.loadDocumentsFromDirectory("test_docs");
    engine.buildIndex();

    int choice;
    string query;
    engine.tfidfSearch(query);

    while (true)
    {
        cout << "\nMini Search Engine\n";
        cout << "--------------------\n";
        cout << "1. Show Documents\n";
        cout << "2. Show Inverted Index\n";
        cout << "3. Boolean Search\n";
        cout << "4. TF-IDFRanked Search\n";
        cout << "5. Phrase Search\n";
        cout << "6.Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            engine.displayDocuments();
        }
        else if (choice == 2) {
            engine.displayIndex();
        }
        else if (choice == 3) {
            cout << "Enter query : ";
            getline(cin, query);
            transform(query.begin(), query.end(), query.begin(),
                [](unsigned char c) { return static_cast<char>(tolower(c)); });
            engine.searchQuery(query);
        }
        else if (choice == 4) {
            cout << "Enter word for TF-IDF ranked search: ";
            getline(cin, query);
            transform(query.begin(), query.end(), query.begin(),
                [](unsigned char c) { return static_cast<char>(tolower(c)); });

            engine.tfidfSearch(query);
        }

        else if (choice == 5) {
            cout << "Enter phrase: ";
            getline(cin, query);
            transform(query.begin(), query.end(), query.begin(),
                [](unsigned char c) { return static_cast<char>(tolower(c)); });
            
            engine.phraseSearch(query);
        }
        else if (choice == 6) {
            cout << "\nExiting search engine....\n";
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }
    engine.tfidfSearch(query);

    return 0;
}