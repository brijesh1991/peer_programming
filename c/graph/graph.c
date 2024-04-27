 #include<stdio.h>
 #include<stdlib.h>


typedef struct node_t{
    struct node_t *next;
}node;


typedef struct edge_t{
    int val;
    int num_vertex;
    int is_visited;
    node **vertex;
}edge;



 void main(){

 }