//
// Created by dobrowol on 30.10.2019.
//

#ifndef EXPRESSIONEVALUATOR_ASTEVALUATOR_H
#define EXPRESSIONEVALUATOR_ASTEVALUATOR_H

#include "../data_model/ASTTree.h"
#include "Evaluator.h"

class ASTEvaluator : public Evaluator{
public:
    int evaluate(std::shared_ptr<ASTTree> tree){
        return tree->evaluate();
    }
};
#endif //EXPRESSIONEVALUATOR_ASTEVALUATOR_H
