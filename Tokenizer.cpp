#include "Tokenizer.h"
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

vector<string> Tokenizer::tokenize(const string& text) {
    string cleaned = text;

    transform(cleaned.begin(), cleaned.end(), cleaned.begin(), ::tolower);

    for (char &c : cleaned) {
        if (ispunct(c))
            c = ' ';
    }

    vector<string> tokens;

    stringstream ss(cleaned);
    string word;

    while (ss >> word) {
        tokens.push_back(word);
    }

    return tokens;
}