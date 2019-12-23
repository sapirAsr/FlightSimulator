#include "Lexer.h"
#include "OpenServerCom.h"

int main() {
    Lexer l = Lexer("/home/sapir/Desktop/ex3/flight_simulator/fly.txt");
    l.lexing();
    OpenServerCom server = OpenServerCom("5400");
    server.execute();
}