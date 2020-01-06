#include "ConnectControlClientCom.h"


void ConnectControlClientCom::clientCon() {
    //create socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        //error
        std::cerr << "Could not create a socket" << std::endl;
        exit(1);
    }
    //We need to create a sockaddr obj to hold address of server
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;//IP4
    address.sin_addr.s_addr = inet_addr("127.0.0.1");  //the localhost address
    address.sin_port = htons(portNum);
    //we need to convert our number (both port & localhost)
    // to a number that the network understands.

    // Requesting a connection with the server
    int is_connect = connect(client_socket, (struct sockaddr *)&address, sizeof(address));
    if (is_connect == -1) {
        std::cerr << "Could not connect to host server"<<std::endl;
        exit(-2);
    } else {
        std::cout<<"Client is now connected to server" <<std::endl;
    }
    while (flag) {
        // clientQ hold all the messages we want to send to simulator
        while (!clientQ.empty()) {
            client.lock();//mutex
            string msg = clientQ.front();
            int is_sent = send(client_socket, msg.c_str(), strlen(msg.c_str()), 0);
            if (is_sent == -1) {
                std::cout << "Error sending message" << std::endl;
            }
            clientQ.pop();
            client.unlock();
        }
    }
    close(client_socket);
}

int ConnectControlClientCom::execute(int i) {
    this->ipAdd = lexerVector.at(i + 1).c_str();
    Interpreter *inter = new Interpreter();
    string exp = setting(lexerVector.at(i + 2));// creating new string that we can interpret.
    this->portNum = (int)inter->interpret(exp)->calculate();
    std::this_thread::sleep_for(std::chrono::seconds(20));
    thread clientThread([=]{clientCon();});
    clientThread.detach();
    return 3;
}