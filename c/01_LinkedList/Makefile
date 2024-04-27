CC=gcc
TARGET=$(PWD)/result.o
CFLAGS  = -g -Wall

#all:ll.o ll_adt.o ll_problem.o
all:
	echo "creating linked list exec"
	$(CC) $(CFLAGS) ll.c ll_adt.c ll_problem.c -o $(TARGET)

clean:
	echo "cleaning linked list exec"
		rm *.o $(TARGET)