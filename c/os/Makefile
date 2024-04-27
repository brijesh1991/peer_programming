#%.o: %.c %.h
CC = gcc
#CFLAGS=
CFLAGS = -g -Wall

thread.o: thread2.c
			$(CC) $(CFLAGS)  -o thread.o -lpthread thread2.c

semaphore.o: semaphore.c
			$(CC) $(CFLAGS)  -o semaphore.o -lpthread semaphore.c


all:
	echo "creating threading Tree exec"
	$(CC) $(CFLAGS) thread.c  -o thread.o  -lpthread 
	$(CC) $(CFLAGS) thread2.c -o thread2.o  -lpthread
	$(CC) $(CFLAGS) mutex.c -o mutex.o  -lpthread 
	$(CC) $(CFLAGS) semaphore.c -o semaphore.o  -lpthread 

clean:
	echo "cleaning Binary Tree exec"
		rm *.o $(TARGET)			