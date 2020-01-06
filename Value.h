#pragma once
#include "Expression.h"

/**
 * This class derived from expression and contains the value of a variable.
 */
class Value: public Expression{
private:
    double val;
public:
    // constructor
    Value(const double value);
    // returns the value
    double calculate();
    // destructor
    ~Value();
};
