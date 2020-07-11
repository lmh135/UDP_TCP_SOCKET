CXX = g++
CC = gcc
client1: client1.o MySocket.o
	$(CXX) -o client1 client1.o MySocket.o -lpthread
client1.o: client1.cpp MySocket.h
	$(CXX) -c client1.cpp
MySocket.o: MySocket.cpp MySocket.h 
	$(CXX) -c MySocket.cpp
clean:
	rm -rf *.o
	rm client1
