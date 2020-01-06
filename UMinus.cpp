//
// Created by sapir on 11/11/2019.
//

#include "UMinus.h"
UMinus::UMinus(Expression *expressionM): UnaryOperator(expressionM){}

double UMinus:: calculate() {
    return (-1)*expression->calculate();
}
UMinus:: ~UMinus(){}