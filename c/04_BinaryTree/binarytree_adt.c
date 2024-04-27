#include "binarytree.h"
#include "Queue.h"

bnode *create_node(int val) {
    bnode *node = (bnode *)calloc(1,sizeof(bnode));
    node->left=node->right= NULL;
    node->val=val;
    return node;
}


int height(bnode *head) {
    if(!head)
        return 0;
    return ((height(head->left)> height(head->right))? height(head->left)+1: height(head->right)+1);
}

int number_node(bnode *head) {
    if (!head)
        return 0;
    return (number_node(head->left) + number_node(head->right)+1);
}


void insert(bnode **head,int val) {
    if(!*head){
        printf("null head inserting %d\n",val);
        *head=create_node(val);
        return;
    }

    printf("inserting %d\n",val);
    Queue *q= createQueue();
    Enqueue(q,*head);
    while(!isEmpty(q)) {
        bnode *node = Dequeue(q);
        if(node->left == NULL) {
            node->left =create_node(val);
            printf("inserting as lchild of %d\n",node->val);
            return;
        } else if (node->right == NULL) {
            node->right = create_node(val);
            printf("inserting as rchild of %d\n",node->val);
            return;
        } else {
            Enqueue(q,node->left);
            Enqueue(q,node->right);
        }
    }    
}

void preorder(bnode *head ) {
    if (!head)
        return;
    printf("%d\t",head->val);
    preorder(head->left);
    preorder(head->right);
}

void postorder(bnode *head ) {
    if (!head)
        return;
    postorder(head->left);
    postorder(head->right);
    printf("%d\t",head->val);    
}


void inorder(bnode *head ) {
    if (!head)
        return;
    inorder(head->left);
    printf("%d\t",head->val); 
    inorder(head->right);
}

void levelorder(bnode *head) {
    if(!head)
        return;
    Queue *q= createQueue();
    Enqueue(q,head);
    while(!isEmpty(q)){
        bnode *node = Dequeue(q);
        printf("%d\t",node->val);
        if(node->left)
            Enqueue(q,node->left);
        if(node->right)
            Enqueue(q,node->right);
    }
}

int ispresent(bnode *head, int val) {
    if (!head){
        return 0;
    }

    if (head->val == val)
        return 1;
    return(ispresent(head->left,val) || ispresent(head->left,val));
}

bnode *find(bnode *head, int val) {
    if (!head){
        return NULL;
    }

    if (head->val == val)
        return head;
    if (find(head->left,val)) 
        return find(head->left,val);
    if( find(head->right,val))
        return find(head->right,val);
    return NULL;
}

bnode *find_last_node(bnode *head) {
    if(!head)
        return NULL;
    bnode *node;
    Queue *q= createQueue();
    Enqueue(q,head);
    while(!isEmpty(q)){
        node = Dequeue(q);
        printf("%d\t",node->val);
        if(node->left)
            Enqueue(q,node->left);
        if(node->right)
            Enqueue(q,node->right);
    }
    printf("\nLast node %d\n",node->val);
    return node;
}

void delete_child(bnode *head, bnode *child) {
    if(!head){
        return;
    }
    //printf("head %d %p %p %p %p \n",
    //       head->val,head,child, head->left, head->right);

    if(head->left == child){
        printf("\nfound as lchild of %d\n",head->val);
        bnode *temp = head->left;
        head->left=NULL;
        free(temp);
        return;
    }
    if(head->right == child){
        printf("\nfound as rchild of %d\n",head->val);
        bnode *temp = head->right;
        head->right=NULL;
        free(temp);
        return;
    }
    delete_child(head->left,child);
    delete_child(head->right,child);

}

void delete_node(bnode *head,int val) {
    bnode *temp = find(head,val);
    if(temp) {
        bnode *last_leaf =find_last_node(head);
        temp->val = last_leaf->val;
        delete_child(head,last_leaf);
    } else {
        printf("\ndidnt find %d to delete\n",val);
    }

}

void print_full_nodes(bnode *head) {
    printf("Printing full nodes\n");
    if(!head)
        return ;
    bnode *node;
    Queue *q= createQueue();
    Enqueue(q,head);
    while(!isEmpty(q)){
        node = Dequeue(q);
        if(node->left)
            Enqueue(q,node->left);
        if(node->right)
            Enqueue(q,node->right);
        if(node->left && node->right)
            printf("%d\t",node->val);
    }
    printf("\n");
}

void print_half_nodes(bnode *head) {
    printf("Printing half nodes\n");
    if(!head)
        return ;
    bnode *node;
    Queue *q= createQueue();
    Enqueue(q,head);
    while(!isEmpty(q)){
        node = Dequeue(q);
        if(node->left)
            Enqueue(q,node->left);
        if(node->right)
            Enqueue(q,node->right);
        if((node->left || node->right ) && (!node->left || !node->right))
            printf("%d\t",node->val);
    }
    printf("\n");
}

void print_leafs(bnode *head) {
    printf("Printing leaf nodes\n");
    if(!head)
        return ;
    bnode *node;
    Queue *q= createQueue();
    Enqueue(q,head);
    while(!isEmpty(q)){
        node = Dequeue(q);
        if(node->left)
            Enqueue(q,node->left);
        if(node->right)
            Enqueue(q,node->right);
        if((node->left == NULL) &&(node->right == NULL)){
            printf("%d\t",node->val);
        }
    }
    printf("\n");
}




void bt_driver(){
    printf("Queue driver");
    Queue *q = createQueue();
    Enqueue(q,create_node(1));
    Enqueue(q,create_node(4));
    printQueue(q);
    Enqueue(q,create_node(21));
    Enqueue(q,create_node(13));
    Enqueue(q,create_node(14));
    printQueue(q);
    Dequeue(q);
    printQueue(q);
}

void bt_insert_driver() {
    printf("insert driver\n");
    bnode *head= NULL;
    insert(&head,1);
    insert(&head,3);
    insert(&head,2);
    insert(&head,4);
    insert(&head,6);
    insert(&head,8);
}

void bt_find_driver(bnode *head) {
    printf("*********************\n");
    printf("Find driver \n");
    printf("*********************\n");
    printf("found 3 %d\n",ispresent(head,3));
    printf("found 30 %d\n",ispresent(head,30));

    printf("found 3 %p\n",find(head,3));
    printf("found 30 %p\n",find(head,30));
    find_last_node(head);
}

void bt_traversal_driver() {
    bnode *head = NULL;
    insert(&head,1);
    insert(&head,3);
    insert(&head,2);
    insert(&head,4);
    insert(&head,6);
    insert(&head,8);
    insert(&head,11);
    printf("\npreorder \n");
    preorder(head);
    printf("\npostorder \n");
    postorder(head);
    printf("\ninorder \n");
    inorder(head);
    printf("\nLevel order\n");
    levelorder(head);
    printf("\n");

    printf("height %d\n",height(head));
    printf("number of node  %d\n",number_node(head));

    bt_find_driver(head);
    
    delete_node(head,11);
    printf("\nLevel order\n");
    levelorder(head);
    printf("\n");
    find_last_node(head);

    print_leafs(head);
    print_half_nodes(head);
    print_full_nodes(head);

    delete_node(head,3);
    printf("\nLevel order\n");
    levelorder(head);
    printf("\n");
}
