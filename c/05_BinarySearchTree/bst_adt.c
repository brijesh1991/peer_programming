#include "bst.h"



// A utility function to create a new BST node
bst* newNode(int item)
{
    bst* temp = (bst*)malloc(sizeof( bst));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// A utility function to do inorder traversal of BST
void inorder(bst* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}
 
/* A utility function to insert
   a new node with given key in
 * BST */
void insert(bst** node, int key)
{

    if (*node == NULL) {
        *node = newNode(key);
        return;
    }

    bst *temp = *node;
    if (key < temp->key)
        insert(temp->left, key);
    else if (key > temp->key)
        insert(temp->right, key);
     return ;
}
 
bst* search(bst* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
       return root;
    
    // Key is greater than root's key
    if (root->key < key)
       return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}


/* Given a non-empty binary search
   tree, return the node
   with minimum key value found in
   that tree. Note that the
   entire tree does not need to be searched. */
bst* minValueNode(bst* node)
{
    bst* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
 
/* Given a binary search tree
   and a key, this function
   deletes the key and
   returns the new root */
bst* deleteNode(bst* root, int key)
{
    // base case
    if (root == NULL)
        return root;
 
    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted
    // is greater than the root's
    // key, then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key,
    // then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            bst* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            bst* temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        bst* temp = minValueNode(root->right);
 
        // Copy the inorder
        // successor's content to this node
        root->key = temp->key;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

//commenting below code as this will not handle absolute right and left child 
//comparision spanning across multiple levels
/*
int checkbst(bst *root){
    if (root == NULL)
        return 0;
    if(root->left != NULL &&  root->right != NULL){
        if (root->key > root->left->key  &&  root->key < root->right->key){
            return(checkbst(root->left) && checkbst(root->right));
        } else
            return 1;
    } else if (root->left == NULL &&  root->right == NULL){
        return 0; 
    } else if ( root->right != NULL){
        if(root->key <root->right->key)
            return checkbst(root->right);
        else
            return 1;
    } else{
        if(root->key > root->left->key)
            return checkbst(root->left);
        else
            return 1;
    }
}
*/
int checkbst(bst *root) {
    static bst *prv= NULL;
    if (root) {
        if (!checkBST(root->left))
            return 0;
        if(prv!= NULL && root->key <= prv->key)
            return 0;
        prv = root;
        return checkBST(root->right);
    }
    return 1;
}


bst* lca(bst *root, int lchild, int rchild){
    if (root == NULL){
        return NULL;
    }
 
    if (root->key < lchild &&  root->key < rchild){
        return lca(root->right,lchild,rchild);
    }else if (root->key > lchild &&  root->key > rchild){
        return lca(root->left,lchild,rchild);
    }else{
        return root;
    }
}

    

int main(){
    printf("Start\n");
    bst *root = NULL ;
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);
    inorder(root);

    printf("is bst : %s\n",checkbst(root)==0?"True":"False");

    return 1;
}
