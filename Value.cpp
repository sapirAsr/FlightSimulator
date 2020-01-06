//
// Created by michal on 29/12/2019.
//

#include "Value.h"
using namespace std;

Value::Value(const double value) {
    this->val = value;
}
double Value:: calculate() {
    return val;
}
Value:: ~Value(){}