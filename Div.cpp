//
// Created by sapir on 11/11/2019.
//

#include "Div.h"
#include "BinaryOperator.h"

Div::Div(Expression *leftD, Expression *rightD): BinaryOpertaor(leftD,rightD){}

double Div::calculate() {
    if (right->calculate() != 0) {
        return left->calculate() / right->calculate();
    } else throw "divison by zero";
}
Div:: ~Div(){}