#pragma once
#include <string>
#include <vector>

class DocumentParser {
public:
    // Converts text to lowercase and strips out messy punctuation symbols
    static std::string normalize_text(const std::string& text);

    // Splits a cleaned string of words by spaces into separate tokens
    static std::vector<std::string> tokenize(const std::string& clean_text);

    // Reads the entire content of a single text file given its name/path
    static std::string read_file(const std::string& file_path);
};