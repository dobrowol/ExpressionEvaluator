//
// Created by dobrowol on 29.10.2019.
//

#ifndef EXPRESSIONEVALUATOR_EVALUATOR_H
#define EXPRESSIONEVALUATOR_EVALUATOR_H


class Evaluator {
public:
    virtual int evaluate(std::shared_ptr<ASTTree> dataModel) = 0;
};


#endif //EXPRESSIONEVALUATOR_EVALUATOR_H
