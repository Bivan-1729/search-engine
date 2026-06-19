#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "DocumentParser.hpp"
#include "InvertedIndex.hpp"

int main() {
    InvertedIndex search_engine;

    // Setup Mock Document Database
    std::vector<std::pair<std::string, std::string>> database = {
        {"doc1.txt", "Data structures and algorithms form the foundation of computer science."},
        {"doc2.txt", "Computer networks routing algorithms handle streaming traffic data efficiently."},
        {"doc3.txt", "Advanced database structures optimize index lookups for computer systems."}
    };

    for (const auto& item : database) {
        std::vector<std::string> tokens = DocumentParser::tokenize(DocumentParser::normalize_text(item.second));
        search_engine.index_document(item.first, tokens);
    }

    std::cout << "=========================================================\n";
    std::cout << "  Day 5 - Engineered Engine & Performance Profiling CLI \n";
    std::cout << "=========================================================\n";
    std::cout << "Indexed 3 documents. System optimized.\n";
    std::cout << "Try multi-word compound queries (e.g., 'computer algorithms').\n\n";

    std::string raw_query;
    while (true) {
        std::cout << "Search Engine 🔍 ";
        if (!std::getline(std::cin, raw_query) || raw_query == "exit") {
            break;
        }
        if (raw_query.empty()) continue;

        // Start High-Precision Stop-watch
        auto start_time = std::chrono::high_resolution_clock::now();

        // Pipeline phase: Tokenize search input string
        std::vector<std::string> query_tokens = DocumentParser::tokenize(DocumentParser::normalize_text(raw_query));
        std::vector<std::string> results = search_engine.search_multi(query_tokens);

        // Stop high-precision stop-watch
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();

        // Display results
        if (results.empty()) {
            std::cout << "   ❌ No document perfectly matches intersection criteria.\n\n";
        } else {
            std::cout << "   📄 Matching Documents:\n";
            for (const auto& doc : results) {
                std::cout << "      • " << doc << "\n";
            }
            // Fallback display if time register rounds to absolute zero on fast CPUs
            if (duration == 0) {
                std::cout << "   ⏱️  Query Executed in: < 100 ns (Ultra-low latency hash hit)\n\n";
            } else {
                std::cout << "   ⏱️  Query Executed in: " << duration << " ns (" << (duration / 1000.0) << " us)\n\n";
            }
        }
    }

    return 0;
}