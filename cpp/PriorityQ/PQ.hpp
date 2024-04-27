#include<iostream>
#include<climits>

class MinHeap
{
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    // Constructor
    MinHeap(int capacity);
  
    // to heapify a subtree with the root at given index
    void MinHeapify(int );
  
    int parent(int i) { return (i-1)/2; }
  
    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }
  
    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }
  
    // to extract the root which is the minimum element
    int extractMin();
  
    // Decreases key value of key at index i to new_val
    void decreaseKey(int i, int new_val);
  
    // Returns the minimum key (key at root) from min heap
    int getMin() { return harr[0]; }
  
    // Deletes a key stored at index i
    void deleteKey(int i);
  
    // Inserts a new key 'k'
    void insertKey(int k);

    void printTree();
};


// A class for Max Heap
class MaxHeap
{
private:
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of Max heap
    int heap_size; // Current number of elements in Max heap
public:
    MaxHeap(int capacity);
    void MaxHeapify(int );
    int parent(int i) { return (i-1)/2; }
    int left(int i) { return (2*i + 1); }
    int right(int i) { return (2*i + 2); }
    int extractMax();

    // optional API
    void changeKey(int i, int new_val);

    // Returns the Maximum key (key at root) from Max heap
    int getMax() { return harr[0]; }
    void deleteKey(int i);
  
    // Inserts a new key 'k'
    void insertKey(int k);

    // Prints the hash structure stored in array format
    void printTree();
};


// A utility function to swap two elements
void swap(int *x, int *y);