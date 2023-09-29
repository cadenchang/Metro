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
