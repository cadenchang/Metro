/*
 *  Train.cpp
 *  Caden Chang
 *  Completed 2/15/22
 *
 *  CS 15 Proj1 MetroSim 
 *
 *  
 *  Contains all member functions of class with implementation
 *  
 *
 */
#include "Train.h"
#include <vector>
#include <iostream>
#include <fstream>

/*
 * name:      Train constructor
 * purpose:   initializes an instance of a train-
 * arguments: none
 * returns:   nothing
 * effects:   none
 */
Train::Train() {
    currStation = 0;
    totalPassengers = 0;
}

/*
 * name:      initializeStations
 * purpose:   fills vector of stations with station structs with given info
 * arguments: string filename which contains all the names of stations
 * returns:   nothing
 * effects:   opens given file
 */
void Train::initializeStations(string filename) {
    ifstream f;
    string tempName = "a";
    f.open(filename);
    int stationCounter = 0;;
    if (not f.is_open()) {
        std::cerr << "Error: could not open file " << filename << endl;
        exit(1);
    } 
    while (not f.eof()){
        getline(f, tempName);
        stations.push_back(Station(tempName, stationCounter));
        stationCounter++;
    }

}

/*
 * name:      printAll
 * purpose:   prints all stations with their passengers as well as passengers
              on the train
 * arguments: std::ostream &output where the text will be printed to
 * returns:   nothing
 * effects:   calls printOnTrain function and printStation
 */
void Train::printAll(std::ostream &output) {
    this->printOnTrain(output);
    output << std::endl;
    for (unsigned int i = 0; i < stations.size(); i++) {
        if (currStation == i) {
            output << "TRAIN: ";
        } else {
            output << "       ";
        }
        stations.at(i).printStation(output);
        output << endl;
        
    }
    output << "Command? ";
}

/*
 * name:      addPassenger
 * purpose:   adds a passenger to the instance at the correct station
 * arguments: to and from station
 * returns:   nothing
 * effects:   creates a passenger struct and calls passenger constructor
 */
void Train::addPassenger(int fromStation, int toStation) {
    totalPassengers++;
    int tempStation = fromStation;
    Passenger result(totalPassengers, fromStation, toStation);
    stations.at(tempStation).passengers.enqueue(result);
    
}

/*
 * name:      outputToFile
 * purpose:   writes arrived passenger info to given file
 * arguments: string filename of file that it's going to be written to
 * returns:   nothing
 * effects:   accesses vector of arrived passengers to print all passengers
 */
void Train::outputToFile(string filename) {
    ofstream os;
    os.open(filename);
    if (not os.is_open()) {
        std::cerr << "Error: could not open file " << filename << endl;
        exit(1);
    } else {
        for (unsigned int i = 0; i < arrived.size(); i++) {
            int stationNum = arrived.at(i).to;
            string stationName = stations.at(stationNum).name;
            os << "Passenger " << arrived.at(i).id 
            << " left train at station " << stationName << endl; 
        }
    }
    os.close();
}

/*
 * name:      moveTrain
 * purpose:   updates the train location while loading and unloading certain
              passengers
 * arguments: none
 * returns:   nothing
 * effects:   calls loadPassengers and unloadPassengers at each station
 */
void Train::moveTrain() {
    this->loadPassengers();
    if (currStation == stations.size()-1) {
        currStation = 0;
    } else {
        currStation++;
    }
    this->unloadPassengers();
}

/*
 * name:      loadPassengers
 * purpose:   private function that transfers all passengers from station
              passengerqueue to the vector of passengers on the train
 * arguments: none
 * returns:   nothing
 * effects:   none
 */
void Train::loadPassengers() {
    int x = stations.at(currStation).passengers.size();
    for (int i = 0; i < x; i++) {
        onTrain.push_back(stations.at(currStation).passengers.front());
        stations.at(currStation).passengers.dequeue();
    }
}

/*
 * name:      unloadPassengers
 * purpose:   checks all passengers to see if they are getting off at curr
              station
 * arguments: none
 * returns:   none
 * effects:   adds passengers who have gotten off to the vector of arrived
              passengers
 */
void Train::unloadPassengers() {
    for (unsigned int i = 0; i < onTrain.size(); i++) {
        unsigned int temp = onTrain.at(i).to;
        if (temp == currStation) {
            arrived.push_back(onTrain.at(i));
            onTrain.erase(onTrain.begin()+i);
            i--;
        }
    }
    
}

/*
 * name:      printOnTrain
 * purpose:   prints all passengers on the train
 * arguments: std::ostream output where text will be directed to
 * returns:   none
 * effects:   calls passenger print function to print each passenger
 */
void Train::printOnTrain(std::ostream &output) {
    std::ostringstream ss;
    for (unsigned int i = 0; i < onTrain.size(); i++) {
        onTrain.at(i).print(ss);
    }
    output << "Passengers on the train: {" + ss.str() + "}";
}
