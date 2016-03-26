cmake_minimum_required(VERSION 3.3)
project(basket)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/PlayerBase.cpp src/PlayerBase.h src/GamesHelper.cpp src/GamesHelper.h)
add_executable(basket ${SOURCE_FILES})