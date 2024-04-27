#include "common.hpp"
#define DQ deque<int>

template<typename T>
void display(const deque<T> &d){
    cout <<"[ ";
    for (const auto &elem:d)
        cout <<elem << " ";
    cout <<"]"<<endl;
}


void test1(){
    DQ d{11,2,3,4,5};
    display(d);

    d = {2,3,4,5,6};
    display(d);

    DQ d1(10,100);
    display(d1);


    d[0] =100;
    d.at(1) =200;
    display(d);
}

void test2(){
    DQ d{0,0,0};
    display(d);
    d.push_back(10);
    d.push_back(20);
    display(d);


    d.push_back(100);
    d.push_back(200);
    display(d);


    cout <<"Front "<<  d.front() <<" \nBack " << d.back()<< "\nSize " << d.size()<< endl;
    
}

void test3(){
    vector<int> vec {1,2,3,4,5,6,7,8,9,10,11,12,13,15};
    DQ d;
    for (const auto &elem:vec) {
        if (elem%2 == 0)
            d.push_back(elem);
        else    
            d.push_front(elem);
    }
    display(d);

    d.clear();
    cout << "push front"<< endl;
    for (const auto &elem:vec) {
        d.push_front(elem);
    }
    display(d);

    d.clear();
    cout << "push back"<< endl;
    for (const auto &elem:vec) {
        d.push_back(elem);
    }
    display(d);

    d.clear();
    cout << "front_inserter"<< endl;
    copy(vec.begin(),vec.end(),front_inserter(d));
    display(d);

    d.clear();
    cout << "back_inserter" << endl;
    copy(vec.begin(),vec.end(),back_inserter(d));
    display(d);

}

int main(){
    /*
    DQ d{1,2,3,4,5};
    DQ d1(10,100);
    deque<string> stooges {
        "Larry", 
        "Moe", 
        "Curly"
    };

    cout <<"Front "<<  d.front() <<" Back " << d.back()<< endl;
    display(d);
    */
    //test1();
    //test2();
    test3();
}

    
