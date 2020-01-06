//
// Created by michal on 24/12/2019.
//

#include "Var.h"

void Var::updateSim(string s) {
    this->sim = s;
}

void Var::updateVal(double v) {
    this->value = v;
}

string Var::getSim() {
    return this->sim;
}

double Var::getVal() {
    return this->value;
}
