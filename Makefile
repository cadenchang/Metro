

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS  = -g3 


MetroSim: main.o MetroSim.o PassengerQueue.o Passenger.o Train.o Station.o
	$(CXX) ${LDFLAGS} -o $@ $^


# builds PassengerQueue.o
PassengerQueue.o: PassengerQueue.cpp PassengerQueue.h Passenger.h 
	$(CXX) $(CXXFLAGS) -c PassengerQueue.cpp

# builds Station.o
Station.o: Station.cpp Passenger.h PassengerQueue.h 
	$(CXX) $(CXXFLAGS) -c Station.cpp

# builds Train.o
Train.o: Train.cpp Passenger.h Station.h
	$(CXX) $(CXXFLAGS) -c Train.cpp

# builds Main.o
main.o: main.cpp MetroSim.h Train.h
	$(CXX) $(CXXFLAGS) -c main.cpp

MetroSim.o: MetroSim.cpp Train.h
	$(CXX) $(CXXFLAGS) -c MetroSim.cpp


clean: 
	rm *.o *~ a.out
