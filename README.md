

# Flight Simulator

Created by: Michal Rahimi and Sapir Asras.

The program takes a txt file with flight instructions and interpret the instructions to commands in the flight simulator that can be implemented by the plane.

## **How The Program Works**

   first we get a fly.txt with the flight instructions and we need to split the instructions into strings. we use a vector to store the information.  
    this operation operated by the Lexer Class.
    
-   we call the Parser Class which creates Command Classes that can be execute, and than executing the Commands.
    

let’s get into some of our main commands:

-   **OpenServerCom** - opens a server that will listen to the flight simulator.  
    the flight simulator sends values of the plane and we use it for flying.
    
-   **ConnectControlClient** - opens a client that will send instructions to the flight simulator.
    
-   **VarDec** - this class sets all the vars into the correct maps according to their declaration. we use 2 maps to store the vars in this program, a map for the vars that gets updates from the simulator and a map for the vars that can be changed by the client and set instructions to the plane.
    
-   **VarUpdate** - this class is in charge of assigning values into vars.
    
-   **Print** - prints data.
    
-   **Sleep** - set a sleep according to the the time that was set in milliseconds.
    
-   **Condition** - this class checks if a condition expression is valid if so we have 2 classes that inherit from the Condition Class: If, While. in those classes we check if the condition is valid if so we execute the set of instructions in the scope of the if or while. we execute it once in the If Command and in the While Command we will execute the set as long as the condition is valid.
    

in all of our classes we can accept expressions as input, to understand the input we use the class Interpreter which accepts strings into the function interpret and returns an Expression that can be calculate the result as a number.

## ****Running Instructions****

please use a linux environment.

-   first you need to install the flight simulator, you can install it in the ubunto software store or you can use this link : [https://www.flightgear.org/](https://www.flightgear.org/)
    
-   after the installation run the flight simulator and go to settings.
    

	in the Additional Settings write the following:

	    --telnet=socket,in,10,127.0.0.1,5402,tcp
	    --generic=socket,out,10,127.0.0.1,5400,tcp,generic_small

-   run our program with a fly.txt, use this command to compile the files:
    

  

	    g++ -std=c++11 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out pthread  

  
after that, run:

    ./a.out fly.txt

-   then open the flight simulator and press fly.
    

the flight simulator will execute the instructions that provided it.

the program will end when it reads a print(“done”).

