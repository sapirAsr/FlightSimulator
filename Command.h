//
// Created by sapir on 22/12/2019.
//

#ifndef EX3_COMMAND_H
#define EX3_COMMAND_H
#include<string>
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <thread>
#include <arpa/inet.h>
#include <unordered_map>
#include <iostream>
#include <list>
#include <iterator>
#include "Var.h"
#include <vector>
#include <queue>
#include "Interpeter.h"

using namespace std;
extern unordered_map<string, Var> fromSim;
extern unordered_map<string, Var> toSim;
extern vector<string> lexerVector;
extern bool flag;
extern queue<string> clientQ;

/**
 * This class is the command interface.
 */
class Command {

public:
    //this func will be implement in all classes that are derived from command.
    virtual int execute(int i) = 0;
    // this function returns a string of an expression that we can interpret.
    string setting(string str);
    //this function checks if a given char is in a vector signs.
    bool inVec(vector<char> vec, char c);
    // checks if a given string is in the to sim map.
    bool isInToSim(string str);
    // checks if a given string is in the from sim map.
    bool isInFromSim(string str);
};


#endif //EX3_COMMAND_H
