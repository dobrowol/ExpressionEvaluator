//
// Created by dobrowol on 28.10.2019.
//

#include <string>
#include <memory>
#include <utility>
#include "parser/Parser.h"
#include "evaluator/Evaluator.h"

class ExpressionEvaluator {
    std::shared_ptr<Parser> parser;
    std::shared_ptr<Evaluator> evaluator;
public:
    ExpressionEvaluator(std::shared_ptr<Parser> parser,
    std::shared_ptr<Evaluator> evaluator):parser(std::move(parser)), evaluator(std::move(evaluator)){}
    int evaluate(std::string expression) {
        return evaluator->evaluate(parser->parse(expression));
    };
};