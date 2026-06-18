#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include <string_view>

class Trie {
private:
    struct TrieNode {
        // unique_ptr ensures that when a parent node is destroyed, 
        // all child nodes are cleanly cleaned up recursively without memory leaks.
        std::unordered_map<char, std::unique_ptr<TrieNode>> children;
        bool is_end_of_word = false;
    };

    std::unique_ptr<TrieNode> root;

    // Helper method for recursive Depth-First Search (DFS) backtracking
    void collect_words(const TrieNode* node, std::string& current_prefix, std::vector<std::string>& results) const;

public:
    Trie();

    // Inserts a word into the Trie. string_view avoids allocations for string literals.
    void insert(std::string_view word);

    // Returns true if the exact word exists in the Trie
    bool search(std::string_view word) const;

    // Returns all words starting with the given prefix (Autocomplete)
    std::vector<std::string> get_suggestions(std::string_view prefix) const;
};