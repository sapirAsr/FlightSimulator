//
// Created by sapir on 22/12/2019.
//

#include "OpenServerCom.h"

OpenServerCom::OpenServerCom(string str){
    this->portStr = str;
}
void OpenServerCom:: serverCon(){
    int port = stoi(this->portStr);

    //create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket"<<std::endl;
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
        std::cerr<<"Could not bind the socket to an IP"<<std::endl;
        exit(1);
    }

    //making socket listen to the port
    if (listen(socketfd,5) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr<<"Error during listening command"<<std::endl;
        exit(1);
    } else{
        std::cout<<"Server is now listening ..."<<std::endl;
    }
        // accepting a client
        int client_socket = accept(socketfd, (struct sockaddr *) &address,
                                   (socklen_t *) &address);

        if (client_socket == -1) {
            std::cerr << "Error accepting client" <<std::endl;
            exit(1);
        }

        //close(socketfd); //closing the listening socket

        //reading from client
        char buffer[1024] = {0};
        int valread = read(client_socket, buffer, 1024);
        while(buffer != "") {
            std::cout << buffer << std::endl;
        }
        //writing back to client
        char *hello = "Hello, I can hear you! \n";
        send(client_socket, hello, strlen(hello), 0);
        std::cout << "Hello message sent\n" << std::endl;


}

int OpenServerCom::execute(){
    std::thread serverThread(&OpenServerCom::serverCon,this);
    serverThread.join();
    return 2;

}

unordered_map<string, double> setInitMap(){
    unordered_map<string,double> xmlMap;
    xmlMap["time_warp"] = 0;
    xmlMap["switches_magnetos"] = 0;
    xmlMap["heading-indicator_offset-deg"] = 0;
    xmlMap["altimeter_indicated-altitude-ft"] = 0;
    xmlMap["altimeter_pressure-alt-ft"] = 0;
    xmlMap["attitude-indicator_indicated-pitch-deg"] = 0;
    xmlMap["attitude-indicator_indicated-roll-deg"] = 0;
    xmlMap["attitude-indicator_internal-pitch-deg"] = 0;
    xmlMap["attitude-indicator_internal-roll-deg"] = 0;
    xmlMap["encoder_indicated-altitude-ft"] = 0;
    xmlMap["encoder_pressure-alt-ft"] = 0;
    xmlMap["gps_indicated-altitude-ft"] = 0;
    xmlMap["gps_indicated-ground-speed-kt"] = 0;
    xmlMap["gps_indicated-vertical-speed"] = 0;
    xmlMap["indicated-heading-deg"] = 0;
    xmlMap["magnetic-compass_indicated-heading-deg"] = 0;
    xmlMap["slip-skid-ball_indicated-slip-skid"] = 0;
    xmlMap["turn-indicator_indicated-turn-rate"] = 0;
    xmlMap["vertical-speed-indicator_indicated-speed-fpm"] = 0;
    xmlMap["flight_aileron"] = 0;
    xmlMap["flight_elevator"] = 0;
    xmlMap["flight_rudder"] = 0;
    xmlMap["flight_flaps"] = 0;
    xmlMap["engine_throttle"] = 0;
    xmlMap["current-engine_throttle"] = 0;
    xmlMap["switches_master-avionics"] = 0;
    xmlMap["switches_starter"] = 0;
    xmlMap[28] = "active-engine_auto-start"
    xmlMap[29] = "flight_speedbrake"
    xmlMap[30] = "c172p_brake-parking"
    xmlMap[31] = "engine_primer"
    xmlMap[32] = "current-engine_mixture"
    xmlMap[33] = "switches_master-bat"
    xmlMap[34] = "switches_master-alt"
    xmlMap[35] = "engine_rpm
}
