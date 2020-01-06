//
// Created by michal on 17/12/2019.
//

#ifndef EX3_LEXER_H
#define EX3_LEXER_H

#include<iostream>
#include<string>
#include <fstream>
#include <sstream>
#include <list>
#include "Command.h"
using namespace std;
extern unordered_map<string,Command*> commandMap;

class Lexer{
private:
    const char *fileName;
    vector<char> operatorVec = {'<', '>', '!', '='};
    ifstream infile;
public:
    // constructor
    Lexer(const char* file);
    // takes the file and split i.
    void lexing();
    // checks if a given char is in the vector operators
    bool inVec(char c);
};


#endif //EX3_LEXER_H
