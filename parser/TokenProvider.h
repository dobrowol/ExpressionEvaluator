//
// Created by dobrowol on 30.10.2019.
//

#ifndef EXPRESSIONEVALUATOR_TOKENPROVIDER_H
#define EXPRESSIONEVALUATOR_TOKENPROVIDER_H

#include <string>
#include "../data_model/ASTTree.h"
#include "../data_model/Integer.h"
#include "../data_model/Operation.h"

class TokenProvider{
    std::string expression;
    std::string::const_iterator current_token;

public:
    TokenProvider(std::string expression):expression(expression), current_token(expression.cbegin()){}
    std::unique_ptr<ASTTree> getNextToken(){
        while(*current_token++ == ' ');

        if(isdigit(*current_token)){
            return std::unique_ptr<Integer>(new Integer(*current_token));
        }
        else if(*current_token == '+'){
            return std::unique_ptr<Operation>()
        }
    }
};
#endif //EXPRESSIONEVALUATOR_TOKENPROVIDER_H
