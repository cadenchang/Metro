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
