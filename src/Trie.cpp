#include "Trie.hpp"

Trie::Trie() : root(std::make_unique<TrieNode>()) {}

// Insert a word letter-by-letter
void Trie::insert(std::string_view word) {
    TrieNode* current = root.get();
    for (char ch : word) {
        // If the character doesn't exist, create it cleanly
        auto& child = current->children[ch];
        if (!child) {
            child = std::make_unique<TrieNode>();
        }
        current = child.get(); // Move pointer to child node
    }
    current->is_end_of_word = true;
}

// Check if a word exists exactly
bool Trie::search(std::string_view word) const {
    const TrieNode* current = root.get();
    for (char ch : word) {
        auto it = current->children.find(ch);
        if (it == current->children.end()) {
            return false;
        }
        current = it->second.get();
    }
    return current->is_end_of_word;
}

// Find matches based on user typing prefix
std::vector<std::string> Trie::get_suggestions(std::string_view prefix) const {
    const TrieNode* current = root.get();
    for (char ch : prefix) {
        auto it = current->children.find(ch);
        if (it == current->children.end()) {
            return {}; // Return empty vector if prefix path doesn't exist
        }
        current = it->second.get();
    }

    std::vector<std::string> results;
    std::string current_prefix(prefix); // Allocate a single buffer once
    collect_words(current, current_prefix, results);
    return results;
}

// Recursive Backtracking DFS
void Trie::collect_words(const TrieNode* node, std::string& current_prefix, std::vector<std::string>& results) const {
    if (!node) return;

    if (node->is_end_of_word) {
        results.push_back(current_prefix);
    }

    for (const auto& [ch, child_node] : node->children) {
        current_prefix.push_back(ch);                            // Choose
        collect_words(child_node.get(), current_prefix, results); // Explore
        current_prefix.pop_back();                               // Un-choose (Backtrack)
    }
}