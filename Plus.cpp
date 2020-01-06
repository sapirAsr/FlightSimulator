//
// Created by sapir on 10/11/2019.
//

#include "Plus.h"

Plus::Plus(Expression *leftP, Expression *rightP): BinaryOpertaor(leftP,rightP){}

double Plus:: calculate() {
    return left->calculate() + right->calculate();
}
Plus:: ~Plus(){}