#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class InvertedIndex {
private:
    // Maps a word to a collection of unique files containing it
    std::unordered_map<std::string, std::unordered_set<std::string>> index;

public:
    // Adds a token and its source file path to the database
    void add_token(const std::string& token, const std::string& file_path);

    // Feeds an entire document's tokenized list into the index structure
    void index_document(const std::string& file_path, const std::vector<std::string>& tokens);

    // Looks up a single term and returns all matching file paths
    std::vector<std::string> search(const std::string& term) const;
};