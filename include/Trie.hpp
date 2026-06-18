#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

class Trie {
private:
    struct TrieNode {
        std::unordered_map<char, std::unique_ptr<TrieNode>> children;
        bool is_end_of_word = false;
    };

    std::unique_ptr<TrieNode> root;
    void collect_words(const TrieNode* node, std::string& current_prefix, std::vector<std::string>& results) const;

public:
    Trie();
    void insert(const std::string& word);                  // Changed from string_view
    bool search(const std::string& word) const;            // Changed from string_view
    std::vector<std::string> get_suggestions(const std::string& prefix) const; // Changed from string_view
};