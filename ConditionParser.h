//
// Created by michal on 28/12/2019.
//

#ifndef EX3_CONDITIONPARSER_H
#define EX3_CONDITIONPARSER_H

#include "Command.h"
extern unordered_map<string,Command*> commandMap;

/**
 * This class derived from command and the condition commands- like while and if are derived
 * from it.
 */
class ConditionParser: public Command {
public:
    // execute the command
    virtual int execute(int i) = 0;
    // checks if the condition is true.
    bool doOperate(double v1, double v2, string oper);
};


#endif //EX3_CONDITIONPARSER_H
