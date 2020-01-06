//
// Created by sapir on 10/11/2019.
//

#ifndef EX1_PLUS_H
#define EX1_PLUS_H

#include "BinaryOperator.h"
/**
 * This class derived from Binary operator and return the result addition of two expressions
 */
class Plus : public BinaryOpertaor{
public:
    // constructor
    Plus(Expression *left, Expression *right);
    // return the result of addition of two expressions
    virtual double calculate();
    // destructor
    virtual ~Plus();

};



#endif //EX1_PLUS_H