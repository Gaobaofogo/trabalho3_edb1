#include "WriteFile.hpp"
#include <fstream>
#include <vector>


void write_corrections_on_file(std::string filename, const std::vector<MispelledWord>& mispelled_words) {
  std::ofstream file(filename);

  if (!file.is_open()) {
    throw "Erro ao abrir o arquivo";
  }

  for (size_t i = 0; i < mispelled_words.size(); ++i) {
    file << mispelled_words[i].word << ":" << std::endl;
    file << " - " << mispelled_words[i].suggestion.word << std::endl;
    file << std::endl;
  }
}