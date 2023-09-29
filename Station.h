/*
 *  Station.h
 *  Caden Chang
 *  Completed 2/22/22
 *
 *  CS 15 Proj1 MetroSim
 *
 *  Header file for station.h struct
 *  station struct contains a PassengerQueue object, int for station id
 *  and string for station name
 *  Was used to easily group station info
 */

#ifndef STATION_H
#define STATION_H

#include <iostream>
#include <ostream>
#include "PassengerQueue.h"
#include "Passenger.h"
#include <string>

using namespace std;

struct Station 
{
    string name;
    int stationID;
    PassengerQueue passengers;

    Station() {
        name = "";
        stationID = 0;
    }

    Station(string newName, int ID) {
        name = newName;
        stationID = ID; 
    }

    Station(string newName, int ID, PassengerQueue &newPassengers) {
        name = newName;
        stationID = ID;
        passengers = newPassengers;
        
    }

    void printStation(std::ostream &output);

};

#endif