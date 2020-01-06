//
// Created by sapir on 22/12/2019.
//

#include "OpenServerCom.h"


void OpenServerCom:: serverCon() {
    int port = stoi(this->portStr);
    //create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket" << std::endl;
        exit(1);
    }
    //bind socket to IP address
    // we first need to create the sockaddr obj.
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(port);
    //we need to convert our number
    // to a number that the network understands.

    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr << "Could not bind the socket to an IP" << std::endl;
        exit(1);
    }
    //making socket listen to the port
    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr << "Error during listening command" << std::endl;
        exit(1);
    } else {
        std::cout << "Server is now listening ..." << std::endl;
    }
    // accepting a client
    int client_socket = accept(socketfd, (struct sockaddr *) &address,
                               (socklen_t *) &address);
    if (client_socket == -1) {
        std::cerr << "Error accepting client" << std::endl;
        exit(1);
    }
    close(socketfd); //closing the listening socket
    //reading from client
    char buffer[1024] = {0};
    setInitMap();
    read(client_socket, buffer, 1024);
    string str;
    string buff;
    string sub;
    int i;
    while(flag) {
    // this while loop will get a buffer and divides it to 36 values
        while (buffer != "") {
            mutexLock.lock();
            // if the previous buffer didnt contain 36 values we will join between the two
            // buffers and create 36 values
            buff += buffer;
            int first = find(buff); // find the index of the first '\n'
            sub = buff.substr(first + 1);
            int end = find(sub); // find the index of the second '\n'
            // if the buffer contained only one '\n'
            if (end != -1) {
                sub = buff.substr(first + 1, end);
            } else {
                sub = buff.substr(0, first);
            }
            for (i = 0; i < sub.length(); i++) {
                // split the string to 36 values
                if (sub[i] != ',') {
                    str += sub[i];
                } else {
                    xmlVector.push_back(str);
                    str = "";
                }
            }
            // push the last value
            xmlVector.push_back(str);
            str = "";
            // if the buffer didn't contain 36 values
            if (xmlVector.size() != 36) {
                buff = buff.substr(first + 1);
            } else {
                // update the val in the from simulator map according to his path and index.
                auto iter = fromSim.begin();
                while (iter != fromSim.end()) {
                    string key = iter->second.getSim();
                    int index = mapOfXml[key];
                    double newVal = stod(xmlVector.at(index));
                    iter->second.updateVal(newVal);
                    iter++;
                }
                buff = "";
            }
            xmlVector.clear();
            fill_n(buffer, 1024, 0);
            sub = "";
            read(client_socket, buffer, 1024);
            mutexLock.unlock();
        }
    }
    close(client_socket);
}

int OpenServerCom::execute(int i) {
    // creates the string that we can send to interpreter.
    string exp = setting(lexerVector.at(i + 1));
    this->portStr = to_string(interperter->interpret(exp)->calculate());
    thread serverThread([=]{serverCon();});
    serverThread.detach();
    return 2;
}

int OpenServerCom::find(string str) {
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == '\n') {
            return i;
        }
    }
    return -1;
}

void OpenServerCom::setInitMap() {
    mapOfXml["/instrumentation/airspeed-indicator/indicated-speed-kt"] = 0;
    mapOfXml["/sim/time/warp"] = 1;
    mapOfXml["/controls/switches/magnetos"] = 2;
    mapOfXml["/instrumentation/heading-indicator/offset-deg"] = 3;
    mapOfXml["/instrumentation/altimeter/indicated-altitude-ft"] = 4;
    mapOfXml["/instrumentation/altimeter/pressure-alt-ft"] = 5;
    mapOfXml["/instrumentation/attitude-indicator/indicated-pitch-deg"] = 6;
    mapOfXml["/instrumentation/attitude-indicator/indicated-roll-deg"] = 7;
    mapOfXml["/instrumentation/attitude-indicator/internal-pitch-deg"] = 8;
    mapOfXml["/instrumentation/attitude-indicator/internal-roll-deg"] = 9;
    mapOfXml["/instrumentation/encoder/indicated-altitude-ft"] = 10;
    mapOfXml["/instrumentation/encoder/pressure-alt-ft"] = 11;
    mapOfXml["/instrumentation/gps/indicated-altitude-ft"] = 12;
    mapOfXml["/instrumentation/gps/indicated-ground-speed-kt"] = 13;
    mapOfXml["/instrumentation/gps/indicated-vertical-speed"] = 14;
    mapOfXml["/instrumentation/heading-indicator/indicated-heading-deg"] = 15;
    mapOfXml["/instrumentation/magnetic-compass/indicated-heading-deg"] = 16;
    mapOfXml["/instrumentation/slip-skid-ball/indicated-slip-skid"] = 17;
    mapOfXml["/instrumentation/turn-indicator/indicated-turn-rate"] = 18;
    mapOfXml["/instrumentation/vertical-speed-indicator/indicated-speed-fpm"] = 19;
    mapOfXml["/controls/flight/aileron"] = 20;
    mapOfXml["/controls/flight/elevator"] = 21;
    mapOfXml["/controls/flight/rudder"] = 22;
    mapOfXml["/controls/flight/flaps"] = 23;
    mapOfXml["/controls/engines/engine/throttle"] = 24;
    mapOfXml["/controls/engines/current-engine/throttle"] = 25;
    mapOfXml["/controls/switches/master-avionics"] = 26;
    mapOfXml["/controls/switches/starter"] = 27;
    mapOfXml["/engines/active-engine/auto-start"] = 28;
    mapOfXml["/controls/flight/speedbrake"] = 29;
    mapOfXml["/sim/model/c172p/brake-parking"] = 30;
    mapOfXml["/controls/engines/engine/primer"] = 31;
    mapOfXml["/controls/engines/current-engine/mixture"] = 32;
    mapOfXml["/controls/switches/master-bat"] = 33;
    mapOfXml["/controls/switches/master-alt"] = 34;
    mapOfXml["/engines/engine/rpm"] = 35;
}