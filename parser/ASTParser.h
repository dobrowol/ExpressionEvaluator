//
// Created by dobrowol on 29.10.2019.
//

#ifndef EXPRESSIONEVALUATOR_ASTPARSER_H
#define EXPRESSIONEVALUATOR_ASTPARSER_H


#include "Parser.h"

class ASTParser : public Parser {
    std::string expression;
    std::string::const_iterator current_token;

    void eatToken(char token);
    std::shared_ptr<ASTTree> expr();
    std::shared_ptr<ASTTree> term();
    std::shared_ptr<ASTTree> factor();
public:
    std::shared_ptr<ASTTree> parse(std::string) override;

};


#endif //EXPRESSIONEVALUATOR_ASTPARSER_H
