//
// Created by sapir on 22/12/2019.
//

#ifndef EX3_OPENSERVERCOM_H
#define EX3_OPENSERVERCOM_H

#include "Command.h"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <mutex>
using namespace std;
extern mutex mutexLock;
/**
 * This class derived from command and create the command that open the server
 *
 */
class OpenServerCom: public Command {
private:
    string portStr;
    unordered_map<string, int> mapOfXml;
    vector<string> xmlVector;
    Interpreter *interperter = new Interpreter();

public:
    // execute the command
    int execute(int i);
    // this func creates the server and accept from the simulator updates.
    void serverCon();
    // create the map of 36 values of xml
    void setInitMap();
    // finds the place in the string that the char is '\n'
    int find(string str);
};


#endif //EX3_OPENSERVERCOM_H