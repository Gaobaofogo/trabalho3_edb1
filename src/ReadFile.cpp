#include "ReadFile.hpp"
#include "types/DictData.hpp"

#include <algorithm>
#include <fstream>
#include <map>
#include <sstream>
#include <utility>


DictData read_dictionary_file(std::string filename) {
  std::ifstream dict_file(filename);

  if (!dict_file.good()) {
    throw "Arquivo não encontrado";
  }

  DictData dict_data;
  std::string line;

  while (std::getline(dict_file, line)) {
    std::stringstream stream_line(line);
    std::string word;

    stream_line >> word;

    dict_data.first.push_back(word);
    dict_data.second[word] = word;
  }

  return dict_data;
}

std::vector<std::string> read_test_file(std::string filename) {
  std::ifstream dict_file(filename);

  if (!dict_file.good()) {
    throw "Arquivo não encontrado";
  }

  std::vector<std::string> test_file_data;
  std::string line;

  while (std::getline(dict_file, line)) {
    std::stringstream stream_line(line);
    std::string word;

    while (stream_line >> word) {
      char last = word[word.size() - 1];

      if (last == ':' || last == '.' || last == ',' || last == '?' ||  last == ';' || last == '!') {
        word = word.substr(0, word.size() - 1);
      }

      // Tirei daqui como deixar as letras em lower case:
      // https://thispointer.com/converting-a-string-to-upper-lower-case-in-c-using-stl-boost-library/#:~:text=int%20c%20)%3B-,int%20tolower%20(%20int%20c%20)%3B,function%20each%20of%20them%20i.e.&text=Output%3A,THIS%20IS%20A%20SAMPLE%20STRING.
      std::for_each(word.begin(), word.end(), [](char & c){
          c = ::tolower(c);
      });

      test_file_data.push_back(word);
    }
  }

  return test_file_data;
}