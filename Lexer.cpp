//
// Created by michal on 17/12/2019.
//

#include "Lexer.h"
#include "Command.h"

Lexer::Lexer(const char* file) {
    this->fileName = file;
}

bool Lexer::inVec(char c) {
    for (char i : this->operatorVec) {
        if (c == i) {
            return true;
        }
    }
    return false;
}

void Lexer::lexing() {
    this->infile.open(fileName);
    string line;
    if(infile) {
        // we will read every time only one line
        while (getline(infile, line)) {
            string newStr;
            int size = strlen(line.c_str());
            int i, j;
            for (i = 0; i < size; i++) {
                if (line[i] == '\t') {
                    continue;
                }
                //this condition is when i get a string like the ip address
                if (line[i] == '"') {
                    newStr += line[i];
                    for (j = i + 1; line[j] != '"'; j++) {
                        newStr += line[j];
                    }
                    newStr += line[j];
                    i = j;
                } else if (line[i] == '-' && line[i + 1] == '>') {
                    // if the string we cerated until now isn't empty
                    if (newStr.length() > 0) {
                        lexerVector.push_back(newStr);
                        newStr = "";
                    }
                    // creates the ->
                    newStr += line[i];
                    newStr += line[i + 1];
                    lexerVector.push_back(newStr);
                    newStr = "";
                    i = i + 1;
                } else if (inVec(line[i])) {
                    // if the string we cerated until now isn't empty
                    if (newStr.length() > 0) {
                        lexerVector.push_back(newStr);
                        newStr = "";
                    }
                    // checks if we have ==, !=, <=, =>
                    if (inVec(line[i + 1])) {
                        newStr += line[i];
                        newStr += line[i + 1];
                        lexerVector.push_back(newStr);
                        newStr = "";
                        j = i + 2;
                        // creates the <-
                    } else if (line[i + 1] == '-') {
                        newStr += line[i];
                        newStr += line[i + 1];
                        lexerVector.push_back(newStr);
                        newStr = "";
                        i = i + 1;
                        continue;
                    } else {
                        // if we have only one operator: >, <, =, -
                        newStr += line[i];
                        lexerVector.push_back(newStr);
                        newStr = "";
                        j = i + 1;
                    }
                    // we want all the sub string between the operator and {
                    for (j; line[j] != '{' && j < size; j++) {
                        if (line[j] != ' ') {
                            newStr += line[j];
                        }
                    }
                    lexerVector.push_back(newStr);
                    newStr = "";
                    // we want to add the {
                    if (line[j] == '{') {
                        newStr += line[j];
                        lexerVector.push_back(newStr);
                        newStr = "";
                        j++;
                    }
                    i = j;
                } else if (line[i] != ' ' && line[i] != '(' && line[i] != ')' && line[i] != ',') {
                    newStr += line[i];
                } else {
                    if(newStr.length() > 0) {
                        lexerVector.push_back(newStr);
                        newStr = "";
                    }
                }
            }
            if (!newStr.empty()) {
                lexerVector.push_back(newStr);
            }
        }
    } else {
        cout << "Cannot open input file" << endl;
        exit(1);
    }
}