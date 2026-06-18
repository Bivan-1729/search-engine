#include <iostream>
#include <string>
#include <vector>
#include "Trie.hpp"

int main() {
    Trie search_bar;

    // Standard std::string vector instead of string_view
    std::vector<std::string> vocabulary = {
        "algorithm", "allocation", "architecture", "array", 
        "binary", "boolean", "backtracking", "buffer",
        "compiler", "computer", "complexity", "cpp"
    };

    for (const std::string& word : vocabulary) {
        search_bar.insert(word);
    }

    std::string user_input;
    std::cout << "===============================================\n";
    std::cout << "  Engineered Search Engine - Autocomplete CLI  \n";
    std::cout << "===============================================\n";
    std::cout << "Type a prefix (or 'exit' to quit): \n\n";

    while (true) {
        std::cout << "Search 🔍 ";
        std::cin >> user_input;

        if (user_input == "exit") {
            std::cout << "Shutting down search systems.\n";
            break;
        }

        std::vector<std::string> suggestions = search_bar.get_suggestions(user_input);

        if (suggestions.empty()) {
            std::cout << "   ❌ No matched keyword suggestions found.\n\n";
        } else {
            std::cout << "   💡 Suggestions:\n";
            for (const std::string& word : suggestions) {
                std::cout << "      • " << word << "\n";
            }
            std::cout << "\n";
        }
    }

    return 0;
}