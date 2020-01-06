//
// Created by michal on 24/12/2019.
//

#include "UpdateVar.h"

int UpdateVar::execute(int i) {
    this->name = lexerVector.at(i);
    Interpreter *inter = new Interpreter();
    string exp = setting(lexerVector.at(i + 2));
    this->value = to_string(inter->interpret(exp)->calculate());
    // create the string of the messages we will send to simulator
    string str = "set " + toSim[this->name].getSim() + " " + value + "\r\n";
    clientQ.push(str);
    return 3;
}