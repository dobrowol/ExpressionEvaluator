//
// Created by dobrowol on 29.10.2019.
//

#ifndef EXPRESSIONEVALUATOR_NEGATIVELITERALORUNARYMINUS_H
#define EXPRESSIONEVALUATOR_NEGATIVELITERALORUNARYMINUS_H
#include <exception>
class NegativeLiteralOrUnaryMinus : public std::exception{
public:
    const char * what () const throw(){
        return "Negative literal or unary minus";
    }
};
#endif //EXPRESSIONEVALUATOR_NEGATIVELITERALORUNARYMINUS_H
