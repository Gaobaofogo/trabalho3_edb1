#include "PrintCorrections.hpp"
#include <iostream>


ConsolePrint print_corrections(const std::vector<MispelledWord>& misspelled_words) {
  for (size_t i = 0; i < misspelled_words.size(); ++i) {
    std::cout << misspelled_words[i].word << ":" << std::endl;
    std::cout << " - " << misspelled_words[i].suggestion.word << std::endl;
    std::cout << std::endl;
  }
}