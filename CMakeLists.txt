cmake_minimum_required(VERSION 3.10)
project(ExpressionEvaluator)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(Google_tests)

add_executable(ExpressionEvaluator main.cpp  ExpressionEvaluator.cpp exceptions/LiteralTooBig.cpp exceptions/NegativeLiteralOrUnaryMinus.h parser/Parser.h data_model/ASTTree.h evaluator/Evaluator.h parser/ASTParser.cpp parser/ASTParser.h data_model/Node.h data_model/Operation.h data_model/Integer.h parser/TokenProvider.h evaluator/ASTEvaluator.h)