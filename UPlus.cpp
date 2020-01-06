//
// Created by sapir on 11/11/2019.
//

#include "UPlus.h"

UPlus::UPlus(Expression *expressionP): UnaryOperator(expressionP){}

double UPlus:: calculate() {
    return expression->calculate();
}
UPlus:: ~UPlus(){}
