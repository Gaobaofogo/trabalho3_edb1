CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
PROJECT(Trabalho_3)

SET(CMAKE_CXX_STANDARD 11)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS_RELEASE "-O3")

INCLUDE_DIRECTORIES(include/)

ADD_EXECUTABLE(
  prog
  src/main.cpp
  src/MispelledWord.cpp
  src/ReadFile.cpp
  src/PrintCorrections.cpp
)