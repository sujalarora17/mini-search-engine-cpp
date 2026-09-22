#include "QueryEngine.h"
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

QueryEngine::QueryEngine(const Indexer& idx)
    : indexer(idx) {}

set<int> QueryEngine::intersection(const set<int>& A,
                                    const set<int>&B) const {

                                        set<int> result;

                                        for (int x : A) 
                                        {
                                            if (B.find(x) != B.end())
                                                result.insert(x);

                                        }

                                        return result;
                                    }

set<int> QueryEngine::unionSet(const set<int>& A,
                                const set<int>& B) const {
                                    set<int> result = A;

                                    for (int x : B) 
                                        result.insert(x);

                                    return result;
                                }

set<int> QueryEngine::search(const string& query) const 
{
    stringstream ss(query);
    string word1, op, word2;
    ss >> word1;

    if(!(ss >> op)) {
        return indexer.getDocuments(word1);
    }

    transform(op.begin(), op.end(), op.begin(),
        [](unsigned char c) { return static_cast<char>(toupper(c)); });

    ss >> word2;

    set<int> docs1 = indexer.getDocuments(word1);
    set<int> docs2 = indexer.getDocuments(word2);

    if (op == "AND") {
        return intersection(docs1, docs2);
    }

    if (op == "OR") 
        return unionSet(docs1, docs2);

    return{};
}