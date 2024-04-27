#include "PQ.hpp"

using namespace std;
  
 
// Constructor: Builds a heap from a given array a[] of given size
MaxHeap::MaxHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}
  
// Inserts a new key 'k'
void MaxHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }
  
    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;
  
    // Fix the Max heap property if it is violated
    while (i != 0 && harr[parent(i)] < harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}
  
// Decreases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void MaxHeap::changeKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] < harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}
  
// Method to remove Maximum element (or root) from Max heap
int MaxHeap::extractMax()
{
    if (heap_size <= 0)
        return -1;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
  
    // Store the Maximum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MaxHeapify(0);
  
    return root;
}
  
  
// This function deletes key at index i. It first reduced value to Maxus
// infinite, then calls extractMax()
void MaxHeap::deleteKey(int i)
{
    changeKey(i, INT_MAX);
    extractMax();
}
  
// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MaxHeap::MaxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < heap_size && harr[l] > harr[i])
        largest = l;
    if (r < heap_size && harr[r] > harr[largest])
        largest = r;
    if (largest != i)
    {
        swap(&harr[i], &harr[largest]);
        MaxHeapify(largest);
    }
}

void MaxHeap::printTree()
{
    cout <<"Size: "<< heap_size << endl;
    for (int i =0;i < heap_size; i++) {
        cout << harr[i] << "\t" ;
    }
    cout << endl;
}


// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
  
// Driver program to test above functions
/*
int main()
{
    MaxHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    //deleting at location 1
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    h.MaxHeapify(0);
    h.printTree();
    cout <<"Extract Max " << h.extractMax() << " "<<endl;
    cout << "Read Max "<< h.getMax() << " "<<endl;
    h.changeKey(2, 1);
    cout << h.getMax() << endl;
    h.printTree();
    return 0;
}
*/