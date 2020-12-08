#include <map>
#include <iostream>

#include "MispelledWord.hpp"
#include "ReadFile.hpp"
#include "WriteFile.hpp"
#include "types/DictData.hpp"


int main(int argc, char* argv[]) {
  if (argc < 3) {
    std::cerr << "Quantidade de argumentos inválida. Por favor, informar ";
    std::cerr << "o arquivo de dicionário e o arquivo de teste." << std::endl;
    std::cerr << "Ex.: ./prog dicionario.txt teste.txt" << std::endl;
    exit(1);
  }

  DictData dict_data = read_dictionary_file(argv[1]);
  std::vector<std::string> test_data = read_test_file(argv[2]);
  std::vector<MispelledWord> misspelled_words;
  std::map<std::string, MispelledWord> history_checked_words;

  for (size_t i = 0; i < test_data.size(); ++i) {
    if (dict_data.second.count(test_data[i]) == 0
        && history_checked_words.count(test_data[i]) == 0) {

      MispelledWord misspelled_word(test_data[i]);


      misspelled_words.push_back(misspelled_word);
      history_checked_words[misspelled_word.word] = misspelled_word;
    }
  }

  for (size_t i = 0; i < dict_data.first.size(); ++i) {
    for (size_t j = 0; j < misspelled_words.size(); ++j) {
      int difference = dict_data.first[i].size() - misspelled_words[j].word.size();

      if (difference > 2 || difference < -2) {
        continue;
      }

      if (misspelled_words[j].suggestion.distance <= 2) {
        break;
      }

      misspelled_words[j].insert(dict_data.first[i]);
    }
  }

  write_corrections_on_file("teste.txt", misspelled_words);

  return 0;
}
