//
// Created by sapir on 22/12/2019.
//

#ifndef EX3_COMMAND_H
#define EX3_COMMAND_H
#include<string>
#include<iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <thread>
#include <arpa/inet.h>
#include <unordered_map>
using namespace std;


class Command {
public:
virtual int execute() = 0;
};


#endif //EX3_COMMAND_H
