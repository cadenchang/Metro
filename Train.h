#ifndef TRAIN_H
#define TRAIN_H
#include <sstream>
#include "Passenger.h"
#include "Station.h"
#include "fstream"
#include <vector>

using namespace std;

class Train
{
public:
    Train();
    void initializeStations(string filename);
    void printAll(std::ostream &output);
    void moveTrain();
    void printOnTrain(std::ostream &output);
    void addPassenger(int from, int to);
    void outputToFile(string filename);

private:

    void loadPassengers();
    void unloadPassengers();
    int totalPassengers;
    unsigned int currStation;
    std::vector<Passenger> onTrain;
    std::vector<Station> stations;
    std::vector<Passenger> arrived;
};
#endif
