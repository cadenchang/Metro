/*
 *  MetroSim.cpp
 *  Caden Chang
 *  Completed 2/22/22
 *
 *  CS 15 Proj1 MetroSim
 *
 *  Implementation of all member functions of MetroSim
 *  
 *  
 *
 */

#include "MetroSim.h"
#include "Passenger.h"
#include "Station.h"
#include "PassengerQueue.h"
#include "Train.h"
#include "fstream"
#include "iostream"

/*
 * name:      MetroSim Constructor
 * purpose:   creates an instance of MetroSim, initializing all stations
 * arguments: string stationsFile that contains station names
 * returns:   nothing
 * effects:   calls initializeStations from Train.h to initialize stations
 */
MetroSim::MetroSim(string stationsFile) {
    greenLine.initializeStations(stationsFile);
}

/*
 * name:      useCommandFile
 * purpose:   handles the case where a file with commands is given for the 
              MetroSim program
 * arguments: string outputfile which is the file where passengers who have
              left the program
              string commandsFile that contains a list of commands for the
              program
              std::ostream output which is where the output will be directed to
 * returns:   nothing
 * effects:   calls commandHelper functions that runs the commandloop
              calls outputToFile, which prints passengers to a given file
 */
void MetroSim::useCommandFile(string outputFile, string commandsFile, 
    std::ostream &output) {
    commandHelper(commandsFile, output);
    greenLine.outputToFile(outputFile);
    output << "Thanks for playing MetroSim. Have a nice day!" << endl;
}

/*
 * name:      commandHelper
 * purpose:   runs commandLoop and reads in commands from commandsFile
 * arguments: string commandsFile that contains commands
              std::ostream output which is where output will be directed to
 * returns:   nothing
 * effects:   calls printAll function from train.cpp
 */
void MetroSim::commandHelper(string commandsFile, std::ostream &output) {
    ifstream f;
    char first;
    f.open(commandsFile);
    if (not f.is_open()) {
        std::cerr << "Error: could not open file " << commandsFile << endl;
        exit(1);
    } 
    while (not f.eof()){
        f >> first;
        if (first == 'p') { //add passenger
            int as, ds;
            f >> as;
            f >> ds;
            greenLine.addPassenger(as, ds);
        } 
        if (first == 'm') { // either metro move or metro finish
            char second;
            f >> second;
            if (second == 'm') { // move
                greenLine.moveTrain();
            }
            if (second == 'f') { // finish
                return;
            }
        }
        greenLine.printAll(output);
    }
}

/*
 * name:      useUserInput
 * purpose:   handles case where user input is given
 * arguments: string outputFile which is the file that arrived passenger info
              will be printed to
 * returns:   nothing
 * effects:   calls commandLoop function and outputToFile function from Train.h
              to actually write to given file
 */
void MetroSim::useUserInput(string outputFile, std::ostream &output) {
    commandLoop(output);
    output << "Thanks for playing MetroSim. Have a nice day!" << endl;
    greenLine.outputToFile(outputFile);
}

/*
 * name:      commandLoop
 * purpose:   asks for user input for commands until m f command is given
 * arguments: std::ostream output which is where output will be directed to
 * returns:   nothing
 * effects:   calls printAll function to print text to specified output
              calls addPassenger and moveTrain from train.h
 */
void MetroSim::commandLoop(std::ostream &output) {
    char first;
    bool running = true;
    while (running) {
        greenLine.printAll(output);
        std::cin >> first;
        if (first == 'p') { //new passenger
            int as;
            int ds;
            std::cin >> as;
            std::cin >> ds;
            greenLine.addPassenger(as, ds); 
        }
        if (first == 'm') { //metro move
            char second;
            std::cin >> second;
            if (second == 'f') {
                running = false;

            }
            if (second == 'm') {
                greenLine.moveTrain();
            }
        } 
        
    }
}
