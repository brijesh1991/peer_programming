CC=gcc
TARGET=stack
CFLAGS  = -g -Wall

#all:ll.o ll_adt.o ll_problem.o
all:
	echo "creating stack exec"
	$(CC) $(CFLAGS) stack.c stack_adt.c stack_problem.c -o $(TARGET)

clean:
	echo "cleaning stack exec"
		rm *.o $(TARGET)