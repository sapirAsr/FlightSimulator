//
// Created by sapir on 22/12/2019.
//

#include "Command.h"

bool Command::inVec(vector<char> vec, char c) {
    for (char i : vec) {
        if (c == i) {
            return true;
        }
    }
    return false;
}

bool Command::isInToSim(string str) {
    for (auto const& x : toSim) {
        if (str == x.first) {
            return true;
        }
    }
    return false;
}

bool Command::isInFromSim(string str) {
    for (auto const& x : fromSim) {
        if (str == x.first) {
            return true;
        }
    }
    return false;
}

string Command::setting(string str) {
    string expression;
    string subStr;
    vector<char> operatorVec = {'(', ')', '+', '-', '*', '/', ' '};
    string val;
    for (char& c : str) {
        if(inVec(operatorVec, c)) {
            if (!subStr.empty()) {
                // return a string of the value of the sub string
                if (isInToSim(subStr)) {
                    val = to_string(toSim[subStr].getVal());
                } else if (isInFromSim(subStr)) {
                    val = to_string(fromSim[subStr].getVal());
                } else {
                    val = subStr;
                }
                // if the value is negative we will add brackets
                if (val[0] == '-') {
                    val = "(" + val + ")";
                }
                expression += val;
                subStr = "";
            }
            expression += c;
        } else {
            subStr += c;
        }
    }
    //checks the final sub string
    if (isInToSim(subStr)) {
        val = to_string(toSim[subStr].getVal());
    } else if (isInFromSim(subStr)) {
        val = to_string(fromSim[subStr].getVal());
    } else {
        val = subStr;
    }
    expression += val;
    return expression;
}