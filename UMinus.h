//
// Created by sapir on 11/11/2019.
//

#ifndef EX1_UMINUS_H
#define EX1_UMINUS_H
#include "UnaryOperator.h"

/**
 * This class derived from Unary operator and creates the negative of expression
 */
class UMinus:public UnaryOperator{
public:
    // constructor
    UMinus(Expression *expression);
    // calculate the unary expression
    virtual double calculate();
    // destructor
    virtual ~UMinus();

};


#endif //EX1_UMINUS_H