#include <iostream>
#include <string>
#include <ostream>
#include "Passenger.h"


/*
 * name:      print
 * purpose:   prints the id, starting station and ending station of passenger
 * arguments: stream of where to print
 * returns:   nothing
 * effects:   none
 */
void Passenger::print(std::ostream &output)
{
        // TODO: print passenger information to the output stream
        //       as described in the assignment specification
        
        output << "[" << std::to_string(id) + ", " 
        + std::to_string(from) + "->" + std::to_string(to) + "]";
         
}
