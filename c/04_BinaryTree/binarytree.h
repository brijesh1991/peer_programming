#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef BT_MACRO

typedef struct bnode_t {
    int val;
    struct bnode_t *left;
    struct bnode_t *right;
}bnode;

bnode *create_node(int val);
int height(bnode *head);
int number_node(bnode *head);

void insert(bnode **head,int val);
void preorder(bnode *head );
void postorder(bnode *head ); 
void inorder(bnode *head );
void levelorder(bnode *head);

int ispresent(bnode *head, int val);
bnode *find(bnode *head, int val);
bnode *find_last_node(bnode *head);
void delete_child(bnode *head, bnode *child);
void delete_node(bnode *head,int val);


void print_full_nodes(bnode *head);
void print_half_nodes(bnode *head);
void print_leafs(bnode *head);

//BT problems
int identical_trees(bnode *t1, bnode *t2);
int same_trees(bnode *t1, bnode *t2);
int symmetric_trees(bnode *t1);
int diameter(bnode *head);
bnode *lca(bnode *head , int  a, int b);

//drivers
void bt_driver();
void bt_insert_driver();
void bt_traversal_driver();
void bt_find_driver(bnode *head);
void identical_trees_driver();
void same_trees_driver();
void symmetric_trees_driver();
void diameter_driver();
void lca_driver();
#define BT_MACRO
#endif