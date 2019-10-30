//
// Created by dobrowol on 30.10.2019.
//

#ifndef EXPRESSIONEVALUATOR_NODE_H
#define EXPRESSIONEVALUATOR_NODE_H

#include <memory>

struct Node {
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    virtual int evaluate() = 0;
    void add_left(std::unique_ptr<Node> node){
        left = std::move(node);
    }
    void add_right(std::unique_ptr<Node> node){
        right = std::move(node);
    }
};
#endif //EXPRESSIONEVALUATOR_NODE_H
