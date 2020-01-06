//
// Created by michal on 26/12/2019.
//

#ifndef EX3_VARDEC_H
#define EX3_VARDEC_H

#include "Command.h"
extern unordered_map<string, Var> fromSim;
extern unordered_map<string, Var> toSim;

/**
 * This class is derived from Command and declares on the var
 */
class VarDec: public Command {
private:
    string name;
    Var v;
public:
    // execute the command
    int execute(int i);
};


#endif //EX3_VARDEC_H
