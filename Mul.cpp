//
// Created by sapir on 11/11/2019.
//

#include "Mul.h"
Mul::Mul(Expression *leftMu, Expression *rightMu): BinaryOpertaor(leftMu,rightMu){}

double Mul:: calculate() {
    return this->left->calculate() * this->right->calculate();
}
Mul:: ~Mul(){}