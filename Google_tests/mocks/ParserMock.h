//
// Created by dobrowol on 19.10.2019.
//

#ifndef PARSER_MOCK_H
#define PARSER_MOCK_H

#include "gmock/gmock.h"
#include "../../parser/Parser.h"

class ParserMock : public Parser<ASTTree> {
public:
    MOCK_METHOD(std::shared_ptr<ASTTree>, parse, (std::string), (override));
};

#endif //PARSER_MOCK_H
