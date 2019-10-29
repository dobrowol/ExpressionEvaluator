//
// Created by dobrowol on 29.10.2019.
//
#include <exception>
class LiteralTooBig : public std::exception{
public:
    const char * what () const throw() {
        return "Literal too big";
    }
};