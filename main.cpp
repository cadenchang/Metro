/*
 *  Main.cpp
 *  Caden Chang
 *  Completed 2/22/22
 *
 *  CS 15 Proj1 MetroSim
 *
 *  Main function that creates and initializes an instance of MetroSim
 *  
 *  
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include "Train.h"
#include "Passenger.h"
#include "PassengerQueue.h"
#include "Station.h"
#include "MetroSim.h"

using namespace std;

int main(int argc, char *argv[])
{   
        string c = argv[0];
        string stationFile = argv[1];
        string output = argv[2];
        MetroSim metro(stationFile);
        if (argc >= 4) { //includes commandFile argument
                string commandFile = argv[3];
                if (argc == 5) { //writes all output to a file
                        string testingFile = argv[4];
                        ofstream os;
                        os.open(testingFile);
                        metro.useCommandFile(output, commandFile, os);
                        os.close();
                } else { //normal commandFile case
                        metro.useCommandFile(output, commandFile, std::cout);
                }  
        } else { // normal user input case
                metro.useUserInput(output, std::cout); 
        }
        return 0;
}
