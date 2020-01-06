//
// Created by sapir on 11/11/2019.
//

#include "Minus.h"
Minus::Minus(Expression *leftM, Expression *rightM): BinaryOpertaor(leftM,rightM){}

double Minus::calculate() {
    return left->calculate() - right->calculate();
}
Minus:: ~Minus(){}