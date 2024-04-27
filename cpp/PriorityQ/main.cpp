#include<iostream>
#include<climits>
#include "PQ.hpp"
using namespace std;


void create_min_heap() {
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    h.MinHeapify(0);
    h.printTree();
    cout <<"Extract Min " << h.extractMin() << " "<<endl;
    cout << "Read Min "<< h.getMin() << " "<<endl;
    h.decreaseKey(2, 1);
    cout << h.getMin()<< endl;
    h.printTree();
}

void create_max_heap() {
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
}
int main() {
    cout  <<endl << endl<< "creating min heap" <<endl;
    create_min_heap();
    cout <<endl << endl<< "creating max heap" <<endl;
    create_max_heap();
    return 0;
}