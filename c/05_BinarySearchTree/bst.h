#include <stdio.h>
#include <stdlib.h>

#ifndef BST_MACRO

#define  INT_MIN -1
#define  INT_MAX 0xFFFF

typedef struct bst_t{
    int key;
    struct bst_t *left,*right;
}bst;

bst* newNode(int item);
void insert(bst **head, int key);
bst* deleteNode(bst* root, int key);
bst * search (bst *head, int key);
void inorder(bst* root);

int is_present(bst *head);
bst* minValueNode(bst* node);
int findmax(bst *head);
void delete_tree(bst **head);


int checkbst(bst *root);
bst* lca(bst *root, int lchild, int rchild);
/*
    bst_to_dll();
    dll_to_bst();
    arr_to_bst()

*/

#define BST_MACRO
#endif
