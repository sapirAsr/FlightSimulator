//
// Created by michal on 23/12/2019.
//

#ifndef EX3_PRINT_H
#define EX3_PRINT_H

#include <iostream>
#include "Command.h"
using namespace std;
extern unordered_map<string, Var> fromSim;
extern unordered_map<string, Var> toSim;

/**
 * This class prints to console
 */
class Print: public Command {
private:
    string text;
public:
    // this func does the print func
    int execute(int i);
    };


#endif //EX3_PRINT_H
