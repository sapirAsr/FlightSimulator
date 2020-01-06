//
// Created by sapir on 11/11/2019.
//

#include "Interpeter.h"
Interpreter::Interpreter() {}

Interpreter::~Interpreter() {}

bool Interpreter:: validMathExp(string str) {
    int bCountO = 0;
    int bCountE = 0;
    int flag = 0;

    for (unsigned int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            bCountO++;
        } else if (str[i] == ')') {
            bCountE++;
        } else if (str[i] == '-' || str[i] == '+' || str[i] == '*' || str[i] == '/') {
            if (str[i + 1] == '-' || str[i + 1] == '+' || str[i + 1] == '*' || str[i + 1] == '/') {
                flag++;
            } else {
                continue;
            }
        }
    }
    if (bCountO != bCountE || flag != 0) {
        return false;
    } else {
        return true;
    }
}

bool Interpreter:: varibleName(string str){
    regex name("[A-Za-z_][A-Za-z0-9_]*");
    return regex_match(str, name);
}

bool Interpreter:: isNumber(string str) {
    int flag = 0;
    for (unsigned int i = 0; i < str.length(); i++) {
        if (isdigit(str[i])) {
            continue;
        } else if (str[i] == '.') {
            flag++;
            continue;
        } else return false;
    }
    if (flag == 0 || flag == 1) {
        return true;
    } else return false;
}

bool Interpreter:: variablesSetCheck(string str){
    regex variablesR("([\\w]+[=][\\w|/.]+[/;])*([\\w]+[=][\\w|/.]+){0,1}");
    return (regex_match(str, variablesR));
}

string Interpreter:: setter(string str) {
    string newStr = "";
    if (this->variables.size() > 0) {
        for (it = variables.begin(); it != variables.end(); ++it) {
            if (newStr.length() == 0) {
                regex r(it->first);
                newStr = regex_replace(str, r, it->second);
            } else {
                regex r(it->first);
                newStr = regex_replace(newStr, r, it->second);
            }
        }
        return newStr;
    } else return str;
}

string Interpreter:: isUMinus(string str) {
    int length = str.length();
    for (int j = 0; j < length; j++) {
        // we create a symbol so that we will know that the minus is unary.
        if((str[j] == '-' && str[j-1]== '(' && isdigit(str[j+1])) ||
           (str[j] == '-' && str[j-1] =='(' ) ||
           (j == 0 && str[j]=='-' && str[j+1] =='(')){
            str[j] = '@';
        }
    }
    return str;
}

string Interpreter:: isUPlus(string str) {
    for (unsigned int j = 0; j < str.length(); j++) {
        // we create a symbol so that we will know that the plus is unary.
        if (str[j] == '+' && isdigit(str[j + 1]) && str[j - 1] == '(') {
            str[j] = '#';
        }
    }
    return str;
}

void Interpreter:: operatorOn(Expression *left, Expression *right, char operat) {
    if (operat == '+') {
        exp = new Plus(left, right);
    } else if (operat == '-') {
        exp = new Minus(left, right);
    } else if (operat == '*') {
        exp = new Mul(left, right);
    } else if (operat == '/') {
        exp = new Div(left, right);
    } else if (operat == '@') {
        exp = new UMinus(left);
    } else if (operat == '#') {
        exp = new UPlus(left);
    }
    numbers.push(exp);
}

int Interpreter:: precedence(char operat) {
    if (operat == '-' || operat == '+' || operat == '@' || operat == '#') {
        return 1;
    }
    else if (operat == '/' || operat == '*') {
        return 2;
    } else {
        return 0;
    }
}

bool Interpreter:: validExp(string str){
    for (unsigned int i = 0; i < str.length(); i++) {
        if (isdigit(str[i]) || str[i] == '(' || str[i] == '*' ||
            str[i] == '+' || str[i] == '-' || str[i] == '/' ||
            str[i] == ')' || str[i] == '@' || str[i] == '#' ||
            str[i] == '.') {
            continue;
        } else {
            return false;
        }
    }
    return true;

}

Expression* Interpreter::interpret(string str) {
    unsigned int i = 0;
    int flag = 0;
    double num = 0;
    int power = -1;
    Expression *val1;
    Expression *val2;
    char op;
    string string1 = str;
    // first we do checking
    string1 = setter(string1);
    string1 = isUMinus(string1);
    string1 = isUPlus(string1);
    if(!validMathExp(string1)){
        throw "illegal math expression";

    } else if(!validExp(string1)) {
        throw "error in setting values";
    }
    for (i = 0; i < string1.length(); i++) {
        if (string1[i]=='('){
            operators.push(string1[i]);
        } else if (isdigit(string1[i]) || string1[i] == '.') {
            // this condition takes the string and create his double version
            num = 0;
            flag = 0;
            power = -1; // if the number is double
            while (i < string1.length() && (isdigit(string1[i]) || string1[i] == '.')) {
                if (isdigit(string1[i]) && flag == 0) {
                    num = (10 * num) + (string1[i] - '0');
                    i++;
                }
                else if ((isdigit(string1[i])) && (flag == 1)) {
                    num += (string1[i] - '0') * pow(10.0, power);
                    power--;
                    i++;
                }
                else if (string1[i] == '.') {
                    if (flag != 0 || i == string1.length() - 1) {
                        throw "error";
                    } else {
                        flag++;
                        i++;
                    }
                }
            }
            i--;
            Expression *e = new Value(num);
            numbers.push(e);
        }
        else if (string1[i] == ')') {
            while (!operators.empty() && operators.top() !='(' ) {
                op = operators.top();
                if (op == '+' || op == '-' || op == '*' || op == '/') {
                    val1 = numbers.top();
                    numbers.pop();
                    val2 = numbers.top();
                    numbers.pop();
                    operatorOn(val2, val1, op); // creates the expressions
                // creates the unary expressions.
                } else if (op == '@') {
                    val1 = numbers.top();
                    numbers.pop();
                    exp = new UMinus(val1);
                    numbers.push(exp);
                } else if (op == '#') {
                    val1 = numbers.top();
                    numbers.pop();
                    exp = new UPlus(val1);
                    numbers.push(exp);
                }
                if (!operators.empty()) {
                    operators.pop();
                }
            }
        } else {
            while (!operators.empty() &&
                   precedence(operators.top()) >= precedence(string1[i])) {
                op = operators.top();
                operators.pop();
                if (op == '+' || op == '-' || op == '*' || op == '/') {
                    val1 = numbers.top();
                    numbers.pop();
                    val2 = numbers.top();
                    numbers.pop();
                    operatorOn(val2, val1, op); // creates expressions
                // creates the unary expressions
                } else if (op == '@') {
                    val1 = numbers.top();
                    numbers.pop();
                    exp = new UMinus(val1);
                    numbers.push(exp);
                } else if (op == '#') {
                    val1 = numbers.top();
                    numbers.pop();
                    exp = new UPlus(val1);
                    numbers.push(exp);
                }
            }
            operators.push(string1[i]);
        }
    }
    while (!operators.empty()) {
        op = operators.top();
        if (op == '+' || op == '-' || op == '*' || op == '/') {
            val1 = numbers.top();
            numbers.pop();
            val2 = numbers.top();
            numbers.pop();
            operatorOn(val2, val1, op);
        } else if (op == '@') {
            val1 = numbers.top();
            numbers.pop();
            exp = new UMinus(val1);
            numbers.push(exp);
        } else if (op == '#') {
            val1 = numbers.top();
            numbers.pop();
            exp = new UPlus(val1);
            numbers.push(exp);
        }
        operators.pop();
    }
    // if our string is only a number
    if (exp == nullptr) {
        return numbers.top();
    }
    return exp;
}
