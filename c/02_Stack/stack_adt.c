#include "stack.h"

// Utility function to add an element x in the stack
void push(struct Node **top, int x) // insert at the beginning
{
    struct Node *nd = (struct Node *)calloc(1,sizeof(struct  Node));
    nd->data = x;
    nd->next = *top;
    *top = nd;
}

// Utility function to add an element x in the stack
void char_push(char_stack **top, char x) // insert at the beginning
{
    char_stack *nd = (char_stack *)calloc(1,sizeof(char_stack));
    nd->data = x;
    nd->next = *top;
    *top = nd;
}

// Utility function to check if the stack is empty or not
int isEmpty(struct Node* top)
{
    return top == NULL;
}

// Utility function to return top element in a stack
// if stack is empty return int_min
int peek(struct Node *top)
{
    if(!isEmpty(top)){
        return top->data;
    } else {
        return INT_MIN;
    }
}

// Utility function to pop top element from the stack
void pop(struct Node** top) // remove at the beginning
{
    struct Node *tmp = *top;
    if(tmp == NULL)
        return;

    *top = &(*tmp->next);
    free(tmp);
    return;
}

char char_pop(char_stack** top) // remove at the beginning
{
    char_stack *tmp = *top;
    char temp;
    if(tmp == NULL)
        return '\0';

    temp = tmp->data;
    *top = &(*tmp->next);
    free(tmp);
    return temp;
}

// Utility function to display elements of the stack
void display(struct Node* top)
{
    while(top) {
        printf("%d \t",top->data);
        top = top->next;
    }
    printf("\n");
}


void delete_stack(struct Node **top){
    struct Node *temp = *top;
    struct Node *next =NULL;
    while(temp){
        next = temp->next;
        free(temp);
        temp = next;
    }
}

void size_stack(struct Node *top) {
    int cnt=0;
    while (top){
        cnt++;
        top =top->next;
    }
}