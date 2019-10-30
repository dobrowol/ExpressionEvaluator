//
// Created by dobrowol on 30.10.2019.
//

#ifndef EXPRESSIONEVALUATOR_OPERATION_H
#define EXPRESSIONEVALUATOR_OPERATION_H

#include "ASTTree.h"

struct Operation : public ASTTree{
    std::shared_ptr<ASTTree> left;
    std::shared_ptr<ASTTree> right;
    char operation;
    Operation(std::shared_ptr<ASTTree> left, char operation, std::shared_ptr<ASTTree> right){
        this->left = std::move(left);
        this->right = std::move(right);
        this->operation = operation;
    };

    int evaluate() override {
        if(operation == '+')
            return right->evaluate() + left->evaluate();
    }
};
#endif //EXPRESSIONEVALUATOR_OPERATION_H
