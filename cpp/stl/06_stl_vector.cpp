#include "Person.hpp"
#define VI vector<int>
//template<typename T>


void display(const vector<int> &vec) {
    cout <<"Sz : " <<vec.size() << "\nCpt : " <<  vec.capacity()<< "\n[ ";
    for(auto &it:vec)
        cout << it << " ";
    cout << "]"<<endl;
}

/*
void display(const vector<T> &vec) {
    cout <<"Sz : " <<vec.size() << "\nCpt : " <<  vec.capacity()<< "\n[ ";
    for(auto &it:vec)
        cout << it << " ";
    cout << "]"<<endl;
}
*/
//briv lambda syntax with for_each block
void display2(const vector<int> &vec) {
    cout <<"Sz : " <<vec.size() << "\nCpt : " <<  vec.capacity()<< "\n[ ";
    for_each(vec.begin(),vec.end(), 
        [](int x) {cout << x << " ";});
    cout <<"]"<<endl;
}

void test1(){
    cout <<"***** Test1 *****"<<endl;
    VI vec{1,2,3,4,5};
    display(vec);

    vec = {2,3,4,5,6};
    display2(vec);

    //create 10 copies of 100 in a vector
    VI vec1(10,100);
    display(vec1);
}

void test2() {
    /*
    push_back()
    shrink_to_fit()
    reserve() 
    */

}

/*
void test4(){
    cout <<"***** Test4 *****"<<endl;
    vector<Person> sto;
    Person p1 {"Larry",18};
    sto.push_back(p1);
    display(sto);
    sto.push_back({"Moe",25});
    display(sto);
    sto.emplace_back("Curly",22);
    display(sto);
} 
*/

void test5(){
    cout <<"***** Test5 *****"<<endl;
    vector<Person> stooges{
        {"Larry",18},
        {"Moe",25},
        {"Curly",30}
    };

    for (auto &it:stooges){
        cout << it<<endl;
    }

    cout << "Front " << stooges.front() << endl;
    cout << "back " << stooges.back() << endl;

}

void test6(){
    VI vec{1,2,3};
    display(vec);
    vec.clear();
    display(vec);


    vec ={1,2,3,4,5,6,7,8};
    display(vec);
    vec.erase(vec.begin(),vec.begin()+2);
    display(vec);


    /*
        clear()
        erease()

    */

}
int main(){
   VI vec{1,2,4,7,9,22};
    test6();
}