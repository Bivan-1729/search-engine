#include <iostream>
#include <cassert>
#include "Trie.hpp"

void test_basic_insertion_and_search() {
    Trie trie;
    trie.insert("apple");
    trie.insert("banana");

    assert(trie.search("apple") == true);
    assert(trie.search("banana") == true);
    assert(trie.search("app") == false); // "app" is a prefix, not a full word yet
    assert(trie.search("orange") == false);
}

void test_autocomplete_suggestions() {
    Trie trie;
    trie.insert("app");
    trie.insert("apple");
    trie.insert("apricot");
    trie.insert("applied");
    trie.insert("banana");

    std::vector<std::string> suggestions = trie.get_suggestions("app");
    
    // Should find "app", "apple", "applied", but NOT "apricot" or "banana"
    assert(suggestions.size() == 3);
    
    std::vector<std::string> empty_suggestions = trie.get_suggestions("xyz");
    assert(empty_suggestions.empty() == true);
}

int main() {
    std::cout << "Running Trie structural tests...\n";
    test_basic_insertion_and_search();
    test_autocomplete_suggestions();
    std::cout << "✅ All Trie implementation tests passed successfully!\n";
    return 0;
}