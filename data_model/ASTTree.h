//
// Created by dobrowol on 29.10.2019.
//

#ifndef EXPRESSIONEVALUATOR_ASTTREE_H
#define EXPRESSIONEVALUATOR_ASTTREE_H


#include "Node.h"

struct ASTTree {

    virtual int evaluate() = 0;

};


#endif //EXPRESSIONEVALUATOR_ASTTREE_H
