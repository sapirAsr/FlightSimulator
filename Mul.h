//
// Created by sapir on 11/11/2019.
//

#ifndef EX1_MUL_H
#define EX1_MUL_H

#include "BinaryOperator.h"

/**
 * This class return the multiplication between two expressions
 */
class Mul: public BinaryOpertaor {
public:
    // constructor
    Mul(Expression *left, Expression *right);
    // returns the result of multiplication
    virtual double calculate();
    // destructor
    virtual ~Mul();
};


#endif //EX1_MUL_H(){}