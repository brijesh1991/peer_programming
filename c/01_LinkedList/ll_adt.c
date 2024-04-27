#include "ll.h"

void print_ll(ll *head){
    while(head != NULL){
        printf("%3d ",head->data);
        head = head->next;
    }
    printf("\n");
}

void insert_at_end(ll **head, int data){
    ll *node = (ll *)calloc(1,sizeof(ll));
    node->data = data;
    node->next = NULL;

    if (*head== NULL){
        //printf("inserting %d at beginning\n",data);
        *head=node;
        return;
    }
    ll *temp =*head;
    while(temp->next != NULL){
        temp= temp->next;
    }
    temp->next = node;
    return;
}

void insert_at_begining(ll **head, int data){
    ll *node = (ll *)calloc(1,sizeof(ll));
    node->data = data;
    node->next = *head;
    *head = node;
}


void delete_node(ll *head, int data){
    ll *temp =head, *prev;

    while(temp != NULL && temp->data !=data){
        prev = temp;
        temp =temp->next;
    }
    if(temp == NULL){
        printf("%d not found in ll\n",data);
        return;
    }
    prev->next = temp->next;
    free(temp);
}


ll* gen_ll() {
    ll *lst = (ll *)calloc(1,sizeof(ll));
    if (lst == NULL) {
        printf("no memory allocated\n");
        return NULL;
    }
    return lst;
}

int get_ll_len(ll *l) {
    int cnt=0;
    while(l){
        cnt++;
        l =l->next;
    }
    return cnt;
}