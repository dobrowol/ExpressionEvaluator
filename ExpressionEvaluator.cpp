//
// Created by dobrowol on 28.10.2019.
//

#include <string>
#include <memory>
#include "parser/Parser.h"
#include "evaluator/Evaluator.h"
#include "data_model/ASTTree.h"

template<class DataModel, class Result>
class ExpressionEvaluator{
    std::unique_ptr<Parser<DataModel>> parser;
    std::unique_ptr<Evaluator<DataModel, Result>> evaluator;
public:
    ExpressionEvaluator(std::unique_ptr<Parser<DataModel>> parser, std::unique_ptr<Evaluator<DataModel, Result>> evaluator):parser(std::move(parser)),
        evaluator(std::move(evaluator)){
    }
    int evaluate(std::string expression){
        ;

        return evaluator->evaluate(parser->parse(expression));};
};