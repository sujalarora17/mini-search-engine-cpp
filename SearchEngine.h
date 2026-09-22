#ifndef SEARCH_ENGINE_H
#define SEARCH_ENGINE_H

#include <vector>
#include <utility>
#include <string>
#include <cmath>
#include "Indexer.h"
#include "QueryEngine.h"

class SearchEngine {
    private:

        std::vector<std::string> documents;
        Indexer indexer;

    public:
        void loadDocuments(const std::string& filename);

        void displayDocuments() const;

        int getDocumentCount() const;

        void buildIndex();
        void displayIndex() const;
        void searchQuery(const std::string& query) const;
        void rankedSearch(const std:: string& word) const;
        void tfidfSearch(const std::string& word) const;
        void phraseSearch(const std::string& phrase) const;
        void loadDocumentsFromDirectory(const std::string& folder);
};
#endif