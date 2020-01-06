//
// Created by michal on 24/12/2019.
//

#ifndef EX3_VAR_H
#define EX3_VAR_H

#include "iostream"
#include<string>
using namespace std;

/**
 * This class creates the variables in our program and contains their sim path and their value
 */
class Var {
private:
    double value;
    string sim;
public:
    // update the sim path
    void updateSim(string s);
    // upadte the value of the var
    void updateVal(double v);
    // returns the sim path
    string getSim();
    // return the value
    double getVal();
};


#endif //EX3_VAR_H
