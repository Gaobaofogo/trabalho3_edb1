#pragma once


#include "types/DictData.hpp"


DictData read_dictionary_file(std::string filename);
std::vector<std::string> read_test_file(std::string filename);