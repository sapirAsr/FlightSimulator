//
// Created by michal on 26/12/2019.
//

#include "VarDec.h"
#include "Interpeter.h"

int VarDec::execute(int i) {
    string str;
    if (lexerVector.at(i + 2) == "=") {
        for (char &c : lexerVector.at(i + 3)) {
            if (c != '"') {
                str += c;
            }
        }
        if (isInToSim(str)) {
            this->v.updateSim(toSim[str].getSim());
        } else {
            this->v.updateSim(fromSim[str].getSim());
        }
    } else {
        for (char &c : lexerVector.at(i + 4)) {
            if (c != '"') {
                str += c;
            }
        }
        this->v.updateSim(str);
    }
    this->name = lexerVector.at(i + 1);
    if (lexerVector.at(i + 2) == "->") {
        this->v.updateVal(0);
        toSim.emplace(name, v);
    } else if(lexerVector.at(i + 2) == "<-") {
        fromSim.emplace(name, v);
    } else {
        Interpreter *inter = new Interpreter();
        string exp = setting(str);
        this->v.updateVal(inter->interpret(exp)->calculate());
        toSim.emplace(name, v);
        return 4;
    }
    return 5;
}