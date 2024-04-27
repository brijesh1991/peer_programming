#include "common.hpp"

template<typename T>
void display(priority_queue<T> pq){
    cout << "[ ";
    while(!pq.empty()){
        cout << pq.top()<< " ";
        pq.pop();
    }
}

int main(){
    priority_queue<int> pq{1,100,20,3,450};
    display(pq);
    return 0;
}