#include "binarytree.h"

int identical_trees(bnode *t1, bnode *t2) {
    if(t1 == NULL && t2 == NULL)
        return 1;
    if((t1 == NULL && t2 != NULL) || (t1 != NULL && t2 == NULL)) {
        return 0;
    }
    return ( identical_trees(t1->left , t2->left) && identical_trees(t1->right , t2->right));
}

int same_trees(bnode *t1, bnode *t2) {
    if(t1 == NULL && t2 == NULL)
        return 1;
    if((t1 == NULL && t2 != NULL) || (t1 != NULL && t2 == NULL)) {
        return 0;
    }
    if(t1->val != t2->val)
        return 0;
    return ( identical_trees(t1->left , t2->left) && identical_trees(t1->right , t2->right));
}    

int symmetric_trees(bnode *t1) {
    if (t1->left == NULL || t1->right == NULL)
        return 0;
    return (same_trees(t1->left,t1->right));
}

int diameter(bnode *head) {
    if (!head)
        return 0;
    int lheight = height(head->left);
    int rheight = height(head->right);

    int final_h = lheight+rheight+1;
    int ldia_max = (diameter(head->left) >diameter(head->right)) ? diameter(head->left):diameter(head->right);

    if (ldia_max > final_h)
        return ldia_max;
    else
        return final_h;
}

bnode *lca(bnode *head , int  a, int b) {
    if(!head)
        return NULL;
    
    if (head->val == a || head->val == b)
        return head;
    
    bnode *l_lca = lca(head->left,a,b);
    bnode *r_lca = lca(head->right,a,b);
    if (l_lca && r_lca)
        return head;
    if (l_lca)
        return l_lca;
    else
        return r_lca;
}

void identical_trees_driver() {
    bnode *t1=NULL;
    insert(&t1,1);
    insert(&t1,2);
    insert(&t1,3);
    insert(&t1,4);
    insert(&t1,5);
    insert(&t1,6);
    insert(&t1,7);

    bnode *t2=NULL;
    insert(&t2,11);
    insert(&t2,12);
    insert(&t2,13);
    insert(&t2,14);
    insert(&t2,15);
    insert(&t2,16);
 
    bnode *t3=NULL;
    insert(&t3,21);
    insert(&t3,22);
    insert(&t3,23);
    insert(&t3,24);
    insert(&t3,25);
    insert(&t3,26);
    insert(&t3,27);

    printf("t1 and t2 are identical %d\n",identical_trees(t1,t2));
    printf("t1 and t3 are identical %d\n",identical_trees(t1,t3));
}

void same_trees_driver() {
    bnode *t1=NULL;
    insert(&t1,1);
    insert(&t1,2);
    insert(&t1,3);
    insert(&t1,4);
    insert(&t1,5);
    insert(&t1,6);
    insert(&t1,7);

    bnode *t2=NULL;
    insert(&t2,11);
    insert(&t2,12);
    insert(&t2,13);
    insert(&t2,14);
    insert(&t2,15);
    insert(&t2,16);
 
    bnode *t3=NULL;
    insert(&t3,21);
    insert(&t3,22);
    insert(&t3,23);
    insert(&t3,24);
    insert(&t3,25);
    insert(&t3,26);
    insert(&t3,27);

    bnode *t4=NULL;
    insert(&t4,21);
    insert(&t4,22);
    insert(&t4,23);
    insert(&t4,24);
    insert(&t4,25);
    insert(&t4,26);
    insert(&t4,27);

    printf("t1 and t2 are same %d\n",same_trees(t1,t2));
    printf("t1 and t3 are same %d\n",same_trees(t1,t3));
    printf("t3 and t4 are same %d\n",same_trees(t3,t4));
}

void symmetric_trees_driver() {
    bnode *t1=NULL;
    insert(&t1,1);
    insert(&t1,2);
    insert(&t1,3);
    insert(&t1,4);
    insert(&t1,5);
    insert(&t1,6);
    insert(&t1,7);
    printf("t1 is symmetrical %d\n",symmetric_trees(t1));

    bnode *t2=NULL;
    insert(&t2,1);
    insert(&t2,2);
    insert(&t2,2);
    insert(&t2,3);
    insert(&t2,4);
    insert(&t2,3);
    insert(&t2,4);
    printf("t2 is symmetrical %d\n",symmetric_trees(t2));
}

void diameter_driver() {
    bnode *head = NULL;
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,4);
    insert(&head,5);
    printf("diameter of head %d\n",diameter(head));

    bnode *t1=NULL;
    insert(&t1,1);
    insert(&t1,2);
    insert(&t1,3);
    insert(&t1,4);
    insert(&t1,5);
    insert(&t1,6);
    insert(&t1,7);
    printf("diameter of t1 %d\n",diameter(t1));
}

void lca_driver() {
    bnode *t1=NULL;
    insert(&t1,1);
    insert(&t1,2);
    insert(&t1,3);
    insert(&t1,4);
    insert(&t1,5);
    insert(&t1,6);
    insert(&t1,7);
    bnode *n1 = lca(t1 , 4 , 7);
    bnode *n2 = lca(t1 , 6 , 7);
    printf("lca1 %d \nlca2 %d\n",n1->val,n2->val);
}