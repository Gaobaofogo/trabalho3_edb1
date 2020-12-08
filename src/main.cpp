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
    if (dict_data.second.count(test_data[i]) == 0) {
      if (history_checked_words.count(test_data[i]) == 1) {
        continue;
      }

      MispelledWord misspelled_word(test_data[i]);

      for (size_t j = 0; j < dict_data.first.size(); ++j) {
        int difference = dict_data.first[j].size() - test_data[i].size();

        if (difference > 2 || difference < -2) {
          continue;
        }

        misspelled_word.insert(dict_data.first[j]);

        if (misspelled_word.suggestion.distance <= 2) {
          break;
        }
      }

      misspelled_words.push_back(misspelled_word);
      history_checked_words[misspelled_word.word] = misspelled_word;
    }
  }

  write_corrections_on_file("teste.txt", misspelled_words);

  return 0;
}
