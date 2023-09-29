/*
 *  Passenger.h
 *  Caden Chang
 *  Completed 2/15/22
 *
 *  CS 15 Proj1 Phase One 
 *
 *  Contains all member function and variable declarations of class
 *  
 *
 */



#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include <iostream>

struct Passenger
{

        int id, from, to;
        
        Passenger()
        {
                id   = -1;
                from = -1;
                to   = -1;
        }

        Passenger(int newId, int arrivalStation, int departureStation)
        {
                id   = newId;
                from = arrivalStation;
                to   = departureStation;
        }

        // TODO: implement the print function in Passenger.cpp
        void print(std::ostream &output);

};

#endif
