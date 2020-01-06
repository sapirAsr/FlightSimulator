//
// Created by sapir on 25/12/2019.
//

#include "Parser.h"
#include "OpenServerCom.h"
#include "ConnectControlClientCom.h"
#include "Print.h"
#include "Sleep.h"
#include "Var.h"
#include "UpdateVar.h"
#include "VarDec.h"
#include "WhileCommand.h"
#include "IfCommand.h"

void Parser::initCommandMap(){
    commandMap["openDataServer"] = new(OpenServerCom);
    commandMap["connectControlClient"] = new (ConnectControlClientCom);
    commandMap["var"] = new(VarDec);
    commandMap["="] = new (UpdateVar);
    commandMap["Sleep"] = new (Sleep);
    commandMap["Print"] = new (Print);
    commandMap["while"] = new (WhileCommand);
    commandMap["if"] = new (IfCommand);
}

int Parser::execute(int i) {
    initCommandMap();
    while (i < lexerVector.size()) {
        Command *c;
        if(lexerVector.at(i + 1) == "="){
             c = commandMap.at("=");
        } else {
             c = commandMap.at(lexerVector.at(i));
        }
        if (c != nullptr) {
            i += c->execute(i);
        }
    }
    return 0;
}