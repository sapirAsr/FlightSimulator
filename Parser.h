//
// Created by sapir on 25/12/2019.
//

#ifndef EX3_PARSER_H
#define EX3_PARSER_H
#include "Command.h"

extern unordered_map<string,Command*> commandMap;

/**
 * This class is derived from command and executes all the commands.
 */
class Parser:public Command {
public:
    // this func execute all the commans in the program
    int execute(int i);
    // init the map of commands
    void initCommandMap();
};


#endif //EX3_PARSER_H