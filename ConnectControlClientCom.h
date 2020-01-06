//
// Created by sapir on 22/12/2019.
//

#ifndef EX3_CONNECTCONTROLCLIENTCOM_H
#define EX3_CONNECTCONTROLCLIENTCOM_H


#include "Command.h"
#include <chrono>
#include "mutex"

extern mutex client;

/**
 * This class opens the client that can connect to the flight simulator.
 */
class ConnectControlClientCom: public Command {
private:
    // ip address
    const char* ipAdd;
    int portNum;
public:
    // this function creates a client that connects to the server and sends him messages.
    void clientCon();
    // execute the command
    int execute(int i);
};


#endif //EX3_CONNECTCONTROLCLIENTCOM_H
