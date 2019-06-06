cmake_minimum_required(VERSION 3.14)
project(HelloWorld)

set(CMAKE_CXX_STANDARD 14)

add_executable(HelloWorld main.cpp main.h produceItems.cpp produceItems.h productionItems.cpp productionItems.h displayProductionStatistics.cpp displayProductionStatistics.h employeeAccounts.cpp employeeAccounts.h)