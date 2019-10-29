//
// Created by dobrowol on 19.10.2019.
//

#ifndef EVALUATOR_MOCK_H
#define EVALUATOR_MOCK_H

#include "gmock/gmock.h"
#include "../../evaluator/Evaluator.h"

class EvaluatorMock : public Evaluator<ASTTree, int> {
public:
    MOCK_METHOD(int, evaluate, (std::shared_ptr<ASTTree>), (override));
};

#endif //EVALUATOR_MOCK_H
