//
// Created by michal on 23/12/2019.
//

#include "Sleep.h"
#include <iostream>

int Sleep::execute(int i) {
    Interpreter *inter = new Interpreter;
    string exp = setting(lexerVector.at(i + 1));
    this->time = to_string(inter->interpret(exp)->calculate());
    this_thread::sleep_for(chrono::milliseconds(stoi(this->time)));
    return 2;
}