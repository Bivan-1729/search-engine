#include "DocumentParser.hpp"
#include <algorithm>
#include <cctype>
#include <sstream>
#include <fstream>

// 1. Purify text strings (lowercase + remove punctuation)
std::string DocumentParser::normalize_text(const std::string& text) {
    std::string result;
    result.reserve(text.size());

    for (char ch : text) {
        if (std::isalnum(static_cast<unsigned char>(ch))) {
            result.push_back(static_cast<char>(std::tolower(static_cast<unsigned char>(ch))));
        } 
        else if (std::isspace(static_cast<unsigned char>(ch))) {
            if (!result.empty() && result.back() != ' ') {
                result.push_back(' ');
            }
        }
    }
    return result;
}

// 2. Slice text by space into string tokens
std::vector<std::string> DocumentParser::tokenize(const std::string& clean_text) {
    std::vector<std::string> tokens;
    std::stringstream ss(clean_text);
    std::string token;

    while (ss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

// 3. Read file contents using standard C++ file streams
std::string DocumentParser::read_file(const std::string& file_path) {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        return ""; // Return empty string if file can't be opened
    }
    
    std::stringstream buffer;
    buffer << file.rdbuf(); // Read the entire file into the buffer
    return buffer.str();
}