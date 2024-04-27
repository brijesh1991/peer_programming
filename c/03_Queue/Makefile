CC=gcc
TARGET=Queue
CFLAGS  = -g -Wall

#all:ll.o ll_adt.o ll_problem.o
all:
	echo "creating Queue exec"
	$(CC) $(CFLAGS) Queue.c Queue_adt.c Queue_problem.c -o $(TARGET)

clean:
	echo "cleaning Queue exec"
		rm *.o $(TARGET)