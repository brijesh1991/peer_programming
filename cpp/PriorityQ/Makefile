CC = g++
CFLAGS = 
#CFLAGS = -Wall -g
  
a.out: main.o MaxHeap.o MinHeap.o
	$(CC) $(CFLAGS) -o a.out main.o MaxHeap.o MinHeap.o
 
# The main.o target can be written more simply
 
main.o: main.cpp PQ.hpp
	$(CC) $(CFLAGS) -c main.cpp
 
MaxHeap.o: MaxHeap.cpp PQ.hpp
	$(CC) $(CFLAGS) -c MaxHeap.cpp

MinHeap.o: MinHeap.cpp PQ.hpp
	$(CC) $(CFLAGS) -c MinHeap.cpp
