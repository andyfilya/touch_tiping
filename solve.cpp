#include <fstream>
#include <iostream>
#include <exception>
#include <algorithm>

#include "solve.h"

namespace solve {

bool operator==(const weight_word &lhs, const weight_word &rhs) {
    return lhs.word == rhs.word;
}

void Solve::get_vector() {
    std::ifstream file;
    // file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    file.open(input_file);

    while (!file.eof()) {
        std::string substring;
        file >> substring;
        words.emplace_back(substring);
    }
}

void Solve::estimate_triples() {
    for (auto word : words) {
        for (unsigned idx = solve::length, sz = word.word.size(); idx <= sz; ++idx) {
            std::string triple{word.word.begin() + idx - solve::length, word.word.begin() + idx};
            auto search = triples.find(triple);
            if (search == triples.end())
                triples.insert({triple, 1});
            else 
                ++search->second;
        }
    }
}

void Solve::estimate_words() {
    for (auto &word : words) {
        if (word.word.size() < solve::length) continue;
        
        word.weight = UINT32_MAX;

        for (unsigned idx = solve::length, sz = word.word.size(); idx <= sz; ++idx) {
            std::string triple{word.word.begin() + idx - solve::length, word.word.begin() + idx};
            auto search = triples.find(triple);
            if (search == triples.end())
                throw std::runtime_error("Incorrect behavior");
            else 
                word.weight = std::min(search->second, word.weight);
        }
    }
}

void Solve::sort_words() {
    std::sort(words.begin(), words.end(), [](const solve::weight_word &lhs, const solve::weight_word &rhs){ return (lhs.weight > rhs.weight) || (lhs.weight == rhs.weight && lhs.word > rhs.word); });
    words.erase(unique(words.begin(), words.end()), words.end());
}

void Solve::print_result() {
    std::ofstream ofile;
    ofile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    ofile.open(output_file);

    for (auto word : words)
        ofile << word.word << " ";
}

} // solve 