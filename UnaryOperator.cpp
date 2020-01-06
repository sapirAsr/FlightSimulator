//
// Created by sapir on 11/11/2019.
//

#include "UnaryOperator.h"
UnaryOperator::UnaryOperator(Expression *exp){
    this->expression = exp;
}

double UnaryOperator:: calculate(){
    return this->expression->calculate();
}

UnaryOperator:: ~UnaryOperator(){}