all: main

main: main.o queuelntList.o
	g++ -std=c++11 -o main main.o queuelntList.o

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

queuelntList.o: queuelntList.cpp queueIntList.h
	g++ -std=c++11 -c queuelntList.cpp

clean:
	rm -f *.o main
