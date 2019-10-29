cmake_minimum_required(VERSION 3.10)
project(ExpressionEvaluator)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(Google_tests)

add_executable(ExpressionEvaluator main.cpp  ExpressionEvaluator.cpp)