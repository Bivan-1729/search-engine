#include "InvertedIndex.hpp"

void InvertedIndex::add_token(const std::string& token, const std::string& file_path) {
    if (token.empty()) return;
    // Insert the file path into the unordered_set for this specific token
    index[token].insert(file_path);
}

void InvertedIndex::index_document(const std::string& file_path, const std::vector<std::string>& tokens) {
    for (const std::string& token : tokens) {
        add_token(token, file_path);
    }
}

std::vector<std::string> InvertedIndex::search(const std::string& term) const {
    auto it = index.find(term);
    if (it == index.end()) {
        return {}; // Return empty list if word isn't in any document
    }
    
    // Convert the internal set to a vector to return to the user interface
    return std::vector<std::string>(it->second.begin(), it->second.end());
}