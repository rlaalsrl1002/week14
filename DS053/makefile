CC = g++
SRC = main.cpp queueInt.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = main

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

main.o: main.cpp queueInt.h
	$(CC) -c main.cpp

queueString.o: queueInt.cpp queueInt.h
	$(CC) -c queueInt.cpp

clean:
	rm -f $(OBJ) $(EXEC)
