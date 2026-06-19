#include <iostream>
#include <string>
#include <vector>
#include "DocumentParser.hpp"
#include "InvertedIndex.hpp"

int main() {
    InvertedIndex search_engine;

    // Simulate Document 1 content
    std::string doc1_name = "doc1.txt";
    std::string doc1_content = "Data structures and algorithms are fundamental to computer science.";
    std::string clean_doc1 = DocumentParser::normalize_text(doc1_content);
    std::vector<std::string> tokens_doc1 = DocumentParser::tokenize(clean_doc1);
    search_engine.index_document(doc1_name, tokens_doc1);

    // Simulate Document 2 content
    std::string doc2_name = "doc2.txt";
    std::string doc2_content = "Computer networks routing algorithms handle traffic processing efficiently.";
    std::string clean_doc2 = DocumentParser::normalize_text(doc2_content);
    std::vector<std::string> tokens_doc2 = DocumentParser::tokenize(clean_doc2);
    search_engine.index_document(doc2_name, tokens_doc2);

    std::cout << "===================================================\n";
    std::cout << "    Day 4 Validation - Inverted Index Database    \n";
    std::cout << "===================================================\n";
    std::cout << "Indexed 2 documents successfully!\n";
    std::cout << "Try searching for terms like 'algorithms', 'computer', or 'networks'.\n\n";

    std::string query;
    while (true) {
        std::cout << "Search Term (or 'exit'): ";
        std::cin >> query;

        if (query == "exit") break;

        // Normalize the search term to match index format
        std::string clean_query = DocumentParser::normalize_text(query);
        std::vector<std::string> matches = search_engine.search(clean_query);

        if (matches.empty()) {
            std::cout << "   ❌ Word not found in any indexed document.\n\n";
        } else {
            std::cout << "   📄 Found in matching document(s):\n";
            for (const std::string& doc : matches) {
                std::cout << "      • " << doc << "\n";
            }
            std::cout << "\n";
        }
    }

    return 0;
}