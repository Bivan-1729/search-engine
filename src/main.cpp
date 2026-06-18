#include <iostream>
#include <string>
#include <vector>
#include "DocumentParser.hpp"

int main() {
    std::string raw_user_text;
    std::cout << "===============================================\n";
    std::cout << "    Document Parser & Tokenizer Validation    \n";
    std::cout << "===============================================\n";
    std::cout << "Type a messy sentence (e.g., 'Hello, World! Data-Structures 101.'):\n\n> ";
    
    std::getline(std::cin, raw_user_text);

    // Process using our new architecture
    std::string clean_text = DocumentParser::normalize_text(raw_user_text);
    std::vector<std::string> tokens = DocumentParser::tokenize(clean_text);

    std::cout << "\n✨ Cleaned Normalized Text: \"" << clean_text << "\"\n";
    std::cout << "📦 Generated Tokens List:\n";
    for (size_t i = 0; i < tokens.size(); ++i) {
        std::cout << "  [" << i << "] -> " << tokens[i] << "\n";
    }

    return 0;
}