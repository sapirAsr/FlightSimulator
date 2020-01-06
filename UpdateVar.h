//
// Created by michal on 24/12/2019.
//

#ifndef EX3_UPDATEVAR_H
#define EX3_UPDATEVAR_H

#include <vector>
#include "Command.h"
#include "Interpeter.h"
extern unordered_map<string, Var> fromSim;
extern unordered_map<string, Var> toSim;

/**
 * This class create the command of assigning
 */
class UpdateVar: public Command {
private:
    string value;
    string name;
public:
    // execute the command
    int execute(int i);
    };


#endif //EX3_UPDATEVAR_H
