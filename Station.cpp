/*
 *  Station.cpp
 *  Caden Chang
 *  Completed 2/22/22
 *
 *  CS 15 Proj1 MetroSim
 *
 *  Implementation for all member functions for station struct
 *  
 *  
 */


#include <iostream>
#include <string>
#include <ostream>
#include "Station.h"
#include "Passenger.h"
#include "PassengerQueue.h"


/*
 * name:      printStation
 * purpose:   prints all passengers in the station as well as station id and
              name in the correct format
 * arguments: std::ostream output where strings will be written to
 * returns:   nothing
 * effects:   calls passenger print function to print each individual passenger
 */
void Station::printStation(std::ostream &output) {
    std::ostringstream ss;
    passengers.print(ss);
    output << "[" + std::to_string(stationID) + "] " << name + " {" 
           + ss.str() + "}";
}
