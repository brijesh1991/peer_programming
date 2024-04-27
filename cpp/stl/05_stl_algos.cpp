#include "common.hpp"

struct Square_Functor{
    void operator() (int x ){
        cout << x*x << " ";
    }
};

void square2(int x) {
    cout << x*x << " " ;
}


int main() {
    Square_Functor square;
    vector<int> vec{1,2,5,7,11};
    vector<int> temp;
    cout << temp.capacity() << " " << temp.size()<<endl;
    cout << " Functors" << endl;
    for_each(vec.begin(),vec.end(),square);
    cout << endl;
    cout << "Functions" << endl;
    for_each(vec.begin(),vec.end(),square2);
    cout << endl;

}