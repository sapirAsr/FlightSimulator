//
// Created by sapir on 11/11/2019.
//

#ifndef EX1_DIV_H
#define EX1_DIV_H

#include "BinaryOperator.h"
/**
 * This class derived from Binary operator and return the result of division of two expressions.
 */

class Div: public BinaryOpertaor {
public:
    //constructor
    Div(Expression *left, Expression *right);
    // return the result of division of two expressions.
    virtual double calculate();
    // desructor
    virtual ~Div();

};


#endif //EX1_DIV_H