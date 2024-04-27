#include <stdio.h>
#include <stdlib.h>
#define INT_MIN -1

// A linked list node
struct Node
{
	int data;		// integer data
	struct Node* next;	// pointer to the next node
};


typedef struct char_stack_t
{
	char data;		// integer data
	struct char_stack_t* next;	// pointer to the next node
}char_stack;

typedef struct Node stack;

//ADT
void push(struct Node **top, int x);
int isEmpty(struct Node* top);
int peek(struct Node *top);
void pop(struct Node** top);
void display(struct Node* top);
void delete_stack(struct Node** top);
void size_stack(struct Node *top);
void char_push(char_stack **s, char val);
char char_pop(char_stack **s);


//Problem 
stack *reverse_stack(stack *s);
int are_brackets_balanced(char expr[]);
int compare_char(char c1, char c2);