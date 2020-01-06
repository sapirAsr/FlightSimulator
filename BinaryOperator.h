//
// Created by sapir on 10/11/2019.
//

#ifndef EX1_BINARYOPERTAOR_H
#define EX1_BINARYOPERTAOR_H
#include <iostream>
#include "Expression.h"

using namespace std;
/**
 * This class derived from Expression and will calculate mathematical expressions.
 */
class BinaryOpertaor: public Expression {
protected:
    Expression* left;
    Expression* right;

public:
    //constructor
    BinaryOpertaor(Expression* leftE, Expression* rightE);
    // return the result of the mathematical expression
    virtual double calculate();
    //desructor
    virtual ~BinaryOpertaor();
};


#endif //EX1_BINARYOPERTAOR_H