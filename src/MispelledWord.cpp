#include "LevenshteinDistance.hpp"
#include "MispelledWord.hpp"


MispelledWord::MispelledWord(): word("") {
}

MispelledWord::MispelledWord(std::string _word) {
  this->word = _word;
}

void MispelledWord::insert(std::string dict_word) {
  SuggestionWord suggestion(
    dict_word,
    LevenshteinDistance(this->word, dict_word)
  );

  if (suggestion.distance < this->suggestion.distance) {
    this->suggestion = suggestion;
  }
}