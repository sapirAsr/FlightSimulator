//
// Created by michal on 28/12/2019.
//

#ifndef EX3_WHILECOMMAND_H
#define EX3_WHILECOMMAND_H

#include "ConditionParser.h"

/**
 * This class is derived from Condition Parser and execute the while command
 */
class WhileCommand: public ConditionParser {
public:
    int execute(int i);
};


#endif //EX3_WHILECOMMAND_H
