cmake_minimum_required(VERSION 3.14)
project(EngineeredSearchEngine VERSION 1.0 LANGUAGES CXX)

# Force C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Main executable source files
# Main executable source files
set(SOURCE_FILES
    src/Trie.cpp
    src/DocumentParser.cpp
    src/InvertedIndex.cpp
    src/main.cpp
)

# Build the main search engine executable
add_executable(search_engine ${SOURCE_FILES})

# Enable Testing Infrastructure
enable_testing()

# Build the Unit Test executable
add_executable(run_tests tests/test_trie.cpp src/Trie.cpp)
add_test(NAME TrieTestSuite COMMAND run_tests)

# Main executable source files