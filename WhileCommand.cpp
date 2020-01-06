//
// Created by michal on 28/12/2019.
//

#include "WhileCommand.h"

int WhileCommand::execute(int i) {
    string key = lexerVector.at(i + 1);
    string key2 = lexerVector.at(i + 3);
    string oper = lexerVector.at(i + 2);
    double val;
    double val2;
    // get the values of the keys
    if (isInToSim(key)) { val = toSim[key].getVal();}
    else { val = fromSim[key].getVal();}
    if (isInToSim(key2)) { val2 = toSim[key2].getVal();}
    else if (isInFromSim(key2)) { val2 = fromSim[key2].getVal();}
    else { val2 = stod(key2);}
    int steps = i;
    // counts the long of the while loop
    while (lexerVector.at(steps) != "}") {
        steps++;
    }
    int index = i + 5;
    // checks if the condition is true
    while (doOperate(val, val2, oper)) {
        while (lexerVector.at(index) != "}") {
            Command *c;
            if(lexerVector.at(index + 1) =="="){
                c = commandMap.at("=");
            } else {
                c = commandMap.at(lexerVector.at(index));
            }
            if (c != nullptr) {
                index += c->execute(index);
            }
        }
        // update the values after one operation
        if (isInToSim(key)) { val = toSim[key].getVal();}
        else { val = fromSim[key].getVal();}
        if (isInToSim(key2)) { val2 = toSim[key2].getVal();}
        else if (isInFromSim(key2)) { val2 = fromSim[key2].getVal();}
        else { val2 = stod(key2);}
        index = i + 5;
    }
    return steps- i + 1;
}