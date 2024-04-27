#include "common.hpp"
#include "Person.hpp"

template<typename T>
void display(priority_queue<T> pq){
    cout << "[ ";
    while(!pq.empty()){
        cout << pq.top()<< " ";
        pq.pop();
    }
    cout <<" ]"<<endl;
}

void test2(){
    priority_queue<Person>pq;
    pq.push(Person{"a",100});
    pq.push(Person{"b",10});
    pq.push(Person{"c",120});
    pq.push(Person{"d",13});
    pq.push(Person{"e",500});

    display(pq);
}
int main(){
    priority_queue<int> pq ;

    for (auto i :{1,100,20,3,450}){
        pq.push(i);
    }
    display(pq);

    test2();
    return 0;
}