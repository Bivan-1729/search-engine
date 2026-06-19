#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class InvertedIndex {
private:
    std::unordered_map<std::string, std::unordered_set<std::string>> index;

public:
    void add_token(const std::string& token, const std::string& file_path);
    void index_document(const std::string& file_path, const std::vector<std::string>& tokens);
    std::vector<std::string> search(const std::string& term) const;
    
    // Day 5 feature: Processes multi-word queries with intersection logic
    std::vector<std::string> search_multi(const std::vector<std::string>& query_tokens) const;
};