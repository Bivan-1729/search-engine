#pragma once
#include <string_view>

class Trie {
public:
    Trie();
    void insert(std::string_view word);
    bool search(std::string_view word) const;
};