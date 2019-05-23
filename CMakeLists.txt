cmake_minimum_required(VERSION 3.14)
project(HelloWorld)

set(CMAKE_CXX_STANDARD 14)

add_executable(HelloWorld main.cpp main.h musicPlayer.cpp product.cpp musicPlayer.h moviePlayer.cpp moviePlayer.h)