#pragma once

#include <string>
#include <vector>

struct SuggestionWord {
  std::string word;
  size_t distance;

  SuggestionWord(): word(""), distance(100000) {};
  SuggestionWord(std::string _word, size_t _distance) {
    this->word = _word;
    this->distance = _distance;
  }
};

struct MispelledWord {
  std::string word;
  SuggestionWord suggestion;

  MispelledWord();
  MispelledWord(std::string _word);
  void insert(std::string dict_word);
};