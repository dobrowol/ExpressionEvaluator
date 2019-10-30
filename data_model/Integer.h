//
// Created by dobrowol on 30.10.2019.
//

#ifndef EXPRESSIONEVALUATOR_INTEGER_H
#define EXPRESSIONEVALUATOR_INTEGER_H

#include "ASTTree.h"
#include <cstdlib>

struct Integer : public ASTTree{
    Integer(char sign){
        value = sign - 48;
    }
    int evaluate() override {
        return value;
    }
    int value;
};
#endif //EXPRESSIONEVALUATOR_INTEGER_H
