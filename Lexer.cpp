//
// Created by michal on 17/12/2019.
//

#include "Lexer.h"

Lexer::Lexer(const char* file) {
    fileName = file;
}

list<string> Lexer::lexing() {
    ifstream infile(fileName);
    string line;
    list <string> strlist;
    if (!infile) {
        cout << "Cannot open input file.\n";
        exit(1);
    }
    while (getline(infile, line))
    {
        string newStr;
        for(char& c : line) {
            if (c == '\t') {
                continue;
            }
            if (c != ' ' && c != '(' && c != ')' && c != ',') {
                newStr += c;
            } else {
                strlist.push_front(newStr);
                newStr = "";
            }
        }
    }
    return strlist;
}