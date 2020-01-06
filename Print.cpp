//
// Created by michal on 23/12/2019.
//

#include "Print.h"
#include "Interpeter.h"

int Print::execute(int i) {
    Interpreter *inter = new Interpreter();
    string str;
    if(lexerVector.at(i + 1)[0] != '"') {
        for (char &c : lexerVector.at(i + 1)) {
            if (c != '"') {
                str += c;
            }
        }
        string exp = setting(str);
        this->text = to_string(inter->interpret(exp)->calculate());
    } else {
        this->text = lexerVector.at(i + 1);
    }
    cout << this->text << endl;
    // ends the program
    if (this->text == "done"){
        flag = false;
    }
    return 2;
}