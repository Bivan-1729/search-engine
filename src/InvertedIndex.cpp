#include "InvertedIndex.hpp"
#include <algorithm>

void InvertedIndex::add_token(const std::string& token, const std::string& file_path) {
    if (token.empty()) return;
    index[token].insert(file_path);
}

void InvertedIndex::index_document(const std::string& file_path, const std::vector<std::string>& tokens) {
    for (const std::string& token : tokens) {
        add_token(token, file_path);
    }
}

std::vector<std::string> InvertedIndex::search(const std::string& term) const {
    auto it = index.find(term);
    if (it == index.end()) return {};
    return std::vector<std::string>(it->second.begin(), it->second.end());
}

// Day 5 multi-word query intersection logic (Fixed Pointer/Iterator Safety)
std::vector<std::string> InvertedIndex::search_multi(const std::vector<std::string>& query_tokens) const {
    if (query_tokens.empty()) return {};

    // Start with the postings set from the first token
    auto first_match = index.find(query_tokens[0]);
    if (first_match == index.end()) return {}; 

    std::unordered_set<std::string> current_intersection = first_match->second;

    // Intersect with subsequent terms
    for (size_t i = 1; i < query_tokens.size(); ++i) {
        auto match = index.find(query_tokens[i]);
        if (match == index.end()) {
            return {}; // One term has zero matches -> overall intersection is empty
        }

        const auto& next_set = match->second;
        std::unordered_set<std::string> next_intersection;

        // Safely build a new intersection set without altering the iterator mid-flight
        for (const auto& doc : current_intersection) {
            if (next_set.find(doc) != next_set.end()) {
                next_intersection.insert(doc);
            }
        }

        current_intersection = std::move(next_intersection);
        if (current_intersection.empty()) return {};
    }

    return std::vector<std::string>(current_intersection.begin(), current_intersection.end());
}