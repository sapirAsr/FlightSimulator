//
// Created by sapir on 11/11/2019.
//

#ifndef EX1_UPLUS_H
#define EX1_UPLUS_H
#include "UnaryOperator.h"

/**
 * This class is derived from unary operator and create the plus unary expression
 */
class UPlus: public UnaryOperator{
public:
    // constructor
    UPlus(Expression *expression);
    // calculate the unary plus expression
    virtual double calculate();
    // destructor
    virtual ~UPlus();

};


#endif //EX1_UPLUS_H
