//
// Created by dobrowol on 29.10.2019.
//

#include "ASTParser.h"
#include "../data_model/Integer.h"
#include "../data_model/Operation.h"

std::shared_ptr<ASTTree> ASTParser::parse(std::string expression){
    this->expression = expression;
    this->current_token = expression.cbegin();
    return expr();
}

std::shared_ptr<ASTTree> ASTParser:: expr() {
    std::shared_ptr<ASTTree> node = term();

    while(*current_token == '+' || *current_token == '-'){
        char token = *current_token;
        if(token == '+'){
            eatToken('+');
        }else if(token == '-'){
            eatToken('-');
        }
        node = std::make_shared<Operation>(node, token, term());
    }
    return node;
}

std::shared_ptr<ASTTree> ASTParser::term() {
    std::shared_ptr<ASTTree> node = factor();

    while(*current_token == '*' || *current_token == '/'){
        char token = *current_token;
        if(token == '*'){
            eatToken('*');
        }else if(token == '/'){
            eatToken('/');
        }
        node = std::make_shared<Operation>(node, token, factor());
    }
    return node;
}

std::shared_ptr<ASTTree> ASTParser:: factor() {
    char token = *current_token;
    std::shared_ptr<ASTTree> node;
    if(isdigit(token)) {
        eatToken(token);
        node = std::make_shared<Integer>(token);
    }
    else if(token =='('){
        eatToken('(');
        node = expr();
        eatToken(')');
    }
    return node;
}


void ASTParser::eatToken(char token) {
    if (*current_token == token) {
        while (++current_token != expression.cend() && *current_token == ' ');
    }
}
