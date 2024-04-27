CC=gcc
TARGET=$(PWD)/result.o
CFLAGS  = -g -Wall

#all:ll.o ll_adt.o ll_problem.o
all:
	echo "creating Binary Tree exec"
	$(CC) $(CFLAGS) binarytree_adt.c binarytree.c binarytree_problem.c Queue_binary_node_adt.c -o $(TARGET)

clean:
	echo "cleaning Binary Tree exec"
		rm *.o $(TARGET)