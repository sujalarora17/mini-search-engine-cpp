# Mini Search Engine (C++)

A modular **mini search engine implemented in C++** demonstrating how **Discrete Mathematics concepts such as Set Theory, Relations, and Hashing power real search systems**.

The project implements the **core architecture of search engines**, including:

* Inverted Index
* Boolean Query Processing
* TF-IDF Ranking
* Phrase Search
* Directory Crawling

This project bridges **theoretical computer science concepts and practical system design**.

---

# Project Motivation

Search engines must retrieve relevant documents efficiently.

Instead of scanning every document for each query, search engines build an **Inverted Index**, which maps:

word → documents containing that word

Example:

hello → {1,2}
world → {1,3}
ai → {3}

This allows queries to be processed using **fast set operations**.

---

# Discrete Mathematics Concepts Used

## Set Theory

Each word corresponds to a **set of documents** containing it.

Example:

hello → {1,2}
world → {1,3}

Query:

hello AND world

Mathematically:

{1,2} ∩ {1,3} = {1}

---

## Relations

The inverted index represents the relation:

R ⊆ Words × Documents

Example pairs:

(hello,1)
(hello,2)
(world,1)
(world,3)

---

## Hashing

Words are stored using hash tables:

```cpp
unordered_map<string, unordered_map<int, vector<int>>>
```

This allows **O(1) average lookup time**.

---

# Features

* Document storage system
* Text tokenization and normalization
* Positional inverted index
* Boolean query processing (AND / OR)
* TF-IDF document ranking
* Phrase search
* Interactive CLI interface
* Directory-based document indexing

---

# Implemented Phases

## Phase 1 — Document Storage

Documents are loaded and stored with unique IDs.

---

## Phase 2 — Tokenization

Text is normalized through:

* Lowercase conversion
* Punctuation removal
* Word splitting

Example:

Input:
Hello, WORLD!!!

Output:

hello
world

---

## Phase 3 — Inverted Index

Builds the mapping:

word → documents

This enables **fast document retrieval**.

---

## Phase 4 — Boolean Query Engine

Supports queries like:

hello
hello AND world
hello OR ai

Using set operations:

A ∩ B
A ∪ B

---

## Phase 5 — TF-IDF Ranking

Documents are ranked by relevance using:

TF-IDF = TF × log(N / DF)

Where:

* TF = term frequency
* DF = document frequency
* N = total documents

---

## Phase 6 — Interactive CLI Interface

Menu-driven interface:

1. Show Documents
2. Show Inverted Index
3. Boolean Search
4. TF-IDF Ranked Search
5. Phrase Search
6. Exit

---

## Phase 7 — Phrase Search

Supports queries like:

"hello world"

This is implemented using a **Positional Inverted Index**, storing word positions in documents.

---

## Phase 8 — Directory Indexing

The engine can index **all `.txt` files inside a folder**.

Example:

```
documents/
   file1.txt
   file2.txt
   file3.txt
```

This transforms the system into a **mini desktop search engine**.

---

# Project Structure

```
mini-search-engine-cpp
│
├── documents/
│   ├── doc1.txt
│   ├── doc2.txt
│   └── doc3.txt
│
├── main.cpp
├── SearchEngine.cpp
├── SearchEngine.h
├── Tokenizer.cpp
├── Tokenizer.h
├── Indexer.cpp
├── Indexer.h
├── QueryEngine.cpp
├── QueryEngine.h
└── README.md
```

---

# Complexity Analysis

Let:

N = number of documents
W = total words

Index construction:

O(W log N)

Search lookup:

O(1) average (hash lookup)

Ranking:

O(k log k)

---

# Technologies Used

* C++
* Standard Template Library
* Hash Tables
* Sets
* File I/O
* Filesystem Library

---

# Learning Outcomes

This project demonstrates:

* Data Structures
* Hash Tables
* Information Retrieval
* Search Engine Architecture
* Discrete Mathematics in software systems
* Modular C++ system design

---

# Author

Sujal Arora

GitHub:
https://github.com/sujalarora17
