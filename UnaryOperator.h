//
// Created by sapir on 11/11/2019.
//

#ifndef EX1_UNARYOPERATOR_H
#define EX1_UNARYOPERATOR_H

#include "Expression.h"

/**
 * This class derived from expression and create the unary expressions.
 */
class UnaryOperator: public Expression {
protected:
    Expression* expression;
public:
    // constructor
    UnaryOperator(Expression *exp);
    // calculate the unary expression
    virtual double calculate();
    // destructor
    virtual ~UnaryOperator();

};
#endif //EX1_UNARYOPERATOR_H