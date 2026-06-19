# High-Performance C++ Search Engine

A lightweight, high-precision in-memory search engine built from scratch in C++. This systems-level project implements an inverted index architecture to parse documents, tokenize text, and perform multi-word Boolean intersection ($AND$) queries with sub-microsecond retrieval latency.

## 🚀 Key Features & Architecture

- **Deterministic Text Pipeline (`DocumentParser`):** Handles automated lowercase normalization and alphanumeric boundary tokenization to cleanly isolate terms across raw text inputs.
- **Inverted Index Structure (`InvertedIndex`):** Utilizes memory-efficient, hash-mapped associative containers (`std::unordered_map` and `std::unordered_set`) to map specialized tokens to specific document targets.
- **Iterator-Safe Set Intersection:** Custom algorithm engineered to perform safe, high-speed multi-word filtering without triggering pointer or iterator invalidation mid-flight.
- **High-Precision Profiling CLI:** Tracks lookups at the hardware clock level using the `<chrono>` library, logging query latency metrics directly in nanoseconds ($ns$).

---

## 📂 Project Structure

```text
search_engine/
├── include/
│   ├── DocumentParser.hpp
│   └── InvertedIndex.hpp
├── src/
│   ├── DocumentParser.cpp
│   ├── InvertedIndex.cpp
│   ├── Trie.cpp
│   └── main.cpp
├── .gitignore
└── README.md

## 🔨 How to Build & Run
```bash
g++ src/DocumentParser.cpp src/InvertedIndex.cpp src/main.cpp -Iinclude -o search_engine
./search_engine


### 💡 Example Evaluation
```text
=========================================================
  Day 5 - Engineered Engine & Performance Profiling CLI 
=========================================================
Indexed 3 documents. System optimized.
Try multi-word compound queries (e.g., 'computer algorithms').

Search Engine 🔍 computer networks
   📄 Matching Documents:
      • doc2.txt
   ⏱️  Query Executed in: < 100 ns (Ultra-low latency hash hit)