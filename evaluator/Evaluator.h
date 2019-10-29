//
// Created by dobrowol on 29.10.2019.
//

#ifndef EXPRESSIONEVALUATOR_EVALUATOR_H
#define EXPRESSIONEVALUATOR_EVALUATOR_H

template <class DataModel, class Result>
class Evaluator {
public:
    virtual Result evaluate(std::shared_ptr<DataModel> dataModel) = 0;
};


#endif //EXPRESSIONEVALUATOR_EVALUATOR_H
