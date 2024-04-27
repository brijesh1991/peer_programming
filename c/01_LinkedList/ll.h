#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct ll_t{
    int data;
    struct ll_t *next;
}ll;


void print_ll(ll *head);
void insert_at_end(ll **head, int data);
void insert_at_begining(ll **head, int data);
void delete_node(ll *head, int data);
int get_ll_len(ll *l);
ll *reverse_k(ll *head, int size);
ll* gen_ll();
int check_palindrome(ll * list);
ll * reverse(ll *cur );