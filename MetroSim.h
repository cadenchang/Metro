/*
 *  MetroSim.h
 *  Caden Chang
 *  Completed 2/22/22
 *
 *  CS 15 Proj1 MetroSim
 *
 *  Declaration of all member functions of MetroSim
 *  Contains an instance of a train
 *  
 *
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include "Passenger.h"
#include "Station.h"
#include "PassengerQueue.h"
#include "Train.h"
#include "fstream"
#include "iostream"

// Put any other necessary includes here


// Put any other structs you need here

class MetroSim
{
public:
    MetroSim(string stationsFile);
    void useCommandFile(string outputFile, string commandsFile, std::ostream &output);
    void useUserInput(string outputFile, std::ostream &output);
    
private:
    Train greenLine;
    void commandLoop(std::ostream &output);
    void commandHelper(string commandsFile, std::ostream &output);
};

#endif
