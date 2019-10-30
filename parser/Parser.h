//
// Created by dobrowol on 29.10.2019.
//

#ifndef EXPRESSIONEVALUATOR_PARSER_H
#define EXPRESSIONEVALUATOR_PARSER_H


#include <memory>
#include "../data_model/ASTTree.h"

template<class DataModel>
class Parser {
public:
    virtual std::shared_ptr<DataModel> parse(std::string expression) = 0;
};


#endif //EXPRESSIONEVALUATOR_PARSER_H
