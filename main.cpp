#include "Lexer.h"
#include "OpenServerCom.h"
#include "Parser.h"
#include <queue>
vector<string> lexerVector;
unordered_map<string,Command*> commandMap;
queue<string> clientQ;
unordered_map<string, Var> fromSim;
unordered_map<string, Var> toSim;
mutex mutexLock;
mutex client;
bool flag;

int main(int argc, char *argv[]) {
    if(argc > 1) {
        flag = true;
        Lexer l = Lexer(argv[1]);
        l.lexing();
        Parser p = Parser();
        p.execute(0);
    }
    return 0;
}