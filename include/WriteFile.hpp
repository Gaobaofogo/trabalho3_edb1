#pragma once


#include "MispelledWord.hpp"
#include <string>


void write_corrections_on_file(std::string filename, const std::vector<MispelledWord>& mispelled_words);