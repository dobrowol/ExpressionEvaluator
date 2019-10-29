cmake_minimum_required(VERSION 3.10)
project(ExpressionEvaluator)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(Google_tests)

add_executable(ExpressionEvaluator main.cpp  ExpressionEvaluator.cpp exceptions/LiteralTooBig.cpp exceptions/NegativeLiteralOrUnaryMinus.h parser/Parser.h data_model/ASTTree.cpp data_model/ASTTree.h evaluator/Evaluator.h parser/ASTParser.cpp parser/ASTParser.h)