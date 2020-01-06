//
// Created by michal on 23/12/2019.
//

#ifndef EX3_SLEEP_H
#define EX3_SLEEP_H

#include "Command.h"
#include <chrono>

extern unordered_map<string, Var> fromSim;
extern unordered_map<string, Var> toSim;

class Sleep: public Command {
private:
    string time;
public:
    // execute the command
    int execute(int i);
};


#endif //EX3_SLEEP_H
