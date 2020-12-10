#pragma once

#include "types/ConsolePrint.hpp"
#include "MispelledWord.hpp"
#include <string>


ConsolePrint print_corrections(const std::vector<MispelledWord>& mispelled_words);