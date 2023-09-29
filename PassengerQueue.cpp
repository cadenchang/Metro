#include "PassengerQueue.h"
#include <vector>
#include <iostream>


using namespace std;

/*
 * name:      PassengerQueue constructor
 * purpose:   creates an empty instance of PassengerQueue
 * arguments: nothing
 * returns:   nothing
 * effects:   nothing, vector is already created
 */
PassengerQueue::PassengerQueue() {}

/*
 * name:      enqueue
 * purpose:   adds a passenger instance to the back of the queue
 * arguments: address of passenger to be added
 * returns:   nothing
 * effects:   adds passenger to back of member vector
 */
void PassengerQueue::enqueue(const Passenger &passenger) {
    pass.push_back(passenger);
}

/*
 * name:      size
 * purpose:   gives the amount of passengers in a queue
 * arguments: nothing
 * returns:   size of vector using vector size function
 * effects:   
 */
int PassengerQueue::size() {
    return pass.size();
}

/*
 * name:      dequeue
 * purpose:   removes front passenger of the passengerqueue
 * arguments: nithing
 * returns:   nothing
 * effects:   throws runtime error if called on empty Passengerqueue object
              removes front element of vector otherwise
 */
void PassengerQueue::dequeue() {
    if (pass.size() == 0) { //empty PassengerQueue
        throw std::runtime_error("cannot dequeue from empty PassengerQueue");
    } else {
        pass.erase(pass.begin());
    }
}

/*
 * name:      PassengerQueue destructor
 * purpose:   clears vector of PassengerQueue
 * arguments: nothing
 * returns:   nothing
 * effects:   calls clear function of vector
 */
PassengerQueue::~PassengerQueue() {
    pass.clear();
    
}

/*
 * name:      front
 * purpose:   gives front passenger of PassengerQueue
 * arguments: nothing
 * returns:   passenger at front of queue
 * effects:   nothing
 */
Passenger PassengerQueue::front() {
    return pass.at(0);
}

/*
 * name:      print
 * purpose:   prints all passengers in PassengerQueue
 * arguments: stream of where to print
 * returns:   nothing
 * effects:   calls print function of Passenger class on individual passengers
 */
void PassengerQueue::print(std::ostream &output) {
    std::ostringstream ss;
    for (unsigned int i = 0; i < pass.size(); i++) {
        pass.at(i).print(output); //print each person individually
    }
    
}
