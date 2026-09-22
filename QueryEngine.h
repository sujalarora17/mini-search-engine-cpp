#ifndef QUERY_ENGINE_H
#define QUERY_ENGINE_H

#include <set>
#include <string>
#include "Indexer.h"

class QueryEngine {
    private: 
    const Indexer& indexer;

    std::set<int> intersection(const std::set<int>& A,
                                const std::set<int>& B) const;
    
    std::set<int> unionSet(const std::set<int>& A,
                            const std::set<int>& B) const;

    public:
        QueryEngine(const Indexer& idx);
        std::set<int> search(const std::string& query) const;
};

#endif