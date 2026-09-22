#ifndef INDEXER_H
#define INDEXER_H

#include <unordered_map>
#include <set>
#include <string>
#include <vector>

class Indexer{
    private:
        std::unordered_map<std::string, std::unordered_map<int, std::vector<int>>> invertedIndex;
       

    public:
    void buildIndex(const std::vector<std::string>& documents);

    void displayIndex() const;
     std::vector<int> phraseSearch(const std::string& w1, const std::string& w2) const;
    std::set<int> getDocuments(const std::string& word) const;
};
#endif