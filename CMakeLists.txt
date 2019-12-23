cmake_minimum_required(VERSION 3.15)
project(ex3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(ex3 main.cpp Lexer.cpp Lexer.h Command.cpp Command.h OpenServerCom.cpp OpenServerCom.h ConnectControlClientCom.cpp ConnectControlClientCom.h)