//
// Created by michal on 28/12/2019.
//
#include "ConditionParser.h"

bool ConditionParser::doOperate(double v1, double v2, string oper) {
    if (oper == "==") {return v1 == v2;}
    else if (oper == "!=") {return v1 != v2;}
    else if (oper == "<") { return v1 < v2;}
    else if (oper == ">") { return v1 > v2;}
    else if (oper == "<=") { return v1 <= v2;}
    else { return v1 >= v2;}
}