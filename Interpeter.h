//
// Created by sapir on 11/11/2019.
//

#ifndef UNTIT_INTERPRETER_H
#define UNTIT_INTERPRETER_H
#include "ex1.h"

using namespace std;
/**
 * This class is responsibale for simplifying expressions and calculate them.
 */
class Interpreter {
private:
    Expression* exp = nullptr;
    map<string, string> variables;
    map<string, string>::iterator it = variables.begin();
    stack<Expression *> numbers;
    stack<char> operators;

public:
    // constructor
    Interpreter();
    // destructor
    virtual ~Interpreter();
    // checks if the mathematical expression is correct
    bool validMathExp(string str);
    // checks if the varibale name is legal
    bool varibleName(string str);
    // checks if the string is a number
    bool isNumber(string str);
    // check if the setting is correct
    bool variablesSetCheck(string str);
    // return a string that contains instead of the variables, their value.
    string setter(string str);
    // checks if the expression is unary minus.
    string isUMinus(string str);
    // checks if the expression is unary plus.
    string isUPlus(string str);
    // creates the new expressions.
    void operatorOn(Expression *left, Expression *right, char operat);
    // checks precedence.
    int precedence(char operat);
    // checks if the expression is valid.
    bool validExp(string str);
    // return expression that we can calculate his value.
    Expression* interpret(string s);
};
#endif