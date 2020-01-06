//
// Created by sapir on 11/11/2019.
//

#ifndef EX1_MINUS_H
#define EX1_MINUS_H

#include "BinaryOperator.h"
/**
 * This class derives from Binary Operator and return the result of subtraction
 */

class Minus: public BinaryOpertaor{
public:
    // constructor
    Minus(Expression *left, Expression *right);
    // returns the resulr of subtraction
    virtual double calculate();
    // destructor
    virtual ~Minus();
};


#endif //EX1_MINUS_H