//
// Created by michal on 28/12/2019.
//

#ifndef EX3_IFCOMMAND_H
#define EX3_IFCOMMAND_H

#include "ConditionParser.h"

/**
 * This class derived from condition parser and execute the if command.
 */
class IfCommand: public ConditionParser {
public:
    int execute(int i);
};


#endif //EX3_IFCOMMAND_H
