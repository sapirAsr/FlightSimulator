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
using namespace std;

class Lexer {
private:
    const char *fileName;

public:
    Lexer(const char* file);

    list<string> lexing();
};


#endif //EX3_LEXER_H