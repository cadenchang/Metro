/*
 *  PassengerQueue.h
 *  Caden Chang
 *  Completed 2/15/22
 *
 *  CS 15 Proj1 Phase One 
 *
 *  Header file for PassengerQueue Class
 *  Contains all member function and variable declarations of class
 *  
 *
 */
#ifndef PASSENGER_QUEUE_H
#define PASSENGER_QUEUE_H
#include <sstream>
#include "Passenger.h"
#include <vector>


class PassengerQueue
{
public:
    PassengerQueue();
     ~PassengerQueue();
    void enqueue(const Passenger &passenger);
    void dequeue();
    int size();
    Passenger front();
    void print(std::ostream &output);
private:
    
    std::vector<Passenger> pass;

};
#endif