//
// Created by sapir on 22/12/2019.
//

#ifndef EX3_OPENSERVERCOM_H
#define EX3_OPENSERVERCOM_H


#include "Command.h"

class OpenServerCom: public Command {
private:
    string portStr;
public:
    OpenServerCom(string str);
    int execute();
    void serverCon();
    };


#endif //EX3_OPENSERVERCOM_H
