#include "Trie.hpp"

Trie::Trie() : root(std::make_unique<TrieNode>()) {}

void Trie::insert(const std::string& word) {
    TrieNode* current = root.get();
    for (char ch : word) {
        auto& child = current->children[ch];
        if (!child) {
            child = std::make_unique<TrieNode>();
        }
        current = child.get();
    }
    current->is_end_of_word = true;
}

bool Trie::search(const std::string& word) const {
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

std::vector<std::string> Trie::get_suggestions(const std::string& prefix) const {
    const TrieNode* current = root.get();
    for (char ch : prefix) {
        auto it = current->children.find(ch);
        if (it == current->children.end()) {
            return {};
        }
        current = it->second.get();
    }

    std::vector<std::string> results;
    std::string current_prefix(prefix);
    collect_words(current, current_prefix, results);
    return results;
}

void Trie::collect_words(const TrieNode* node, std::string& current_prefix, std::vector<std::string>& results) const {
    if (!node) return;

    if (node->is_end_of_word) {
        results.push_back(current_prefix);
    }

    // Replace the old structured binding loop with this traditional loop:
    for (const auto& pair : node->children) {
        char ch = pair.first;
        const auto& child_node = pair.second;

        current_prefix.push_back(ch);                            // Choose
        collect_words(child_node.get(), current_prefix, results); // Explore
        current_prefix.pop_back();                               // Un-choose (Backtrack)
    }
}