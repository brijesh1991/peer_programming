#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
class Item {
    private:
        string name;
        T value;

    public:
        Item(string name, T value)
            :name{name}, value{value}
            {}
        string get_name() const {return name;}
        T get_value() const {return value;}
        void print_class() const {cout <<"Name : "<< name << "\tValue : "<< value<< endl; }
};


template<typename T1, typename T2>
class My_pair {
    private:
        T1 first;
        T2 second;
    public:
        My_pair(T1 first,T2 second): first{first}, second{second}
        {}
        T1 getfirst() const {return first;}
        T2 getsecond() const { return second;}
        void print_class_member() const { cout << "T1 : " << first << "\tT2 : "<< second<<endl;}
};

int main() {
    Item<int> i1 {"larry",1};
    i1.print_class();

    vector<Item<double>> vec {};
    vec.push_back(Item<double>{"Larry", 100.0});
    vec.push_back(Item<double>{"Moe", 200.0});
    vec.push_back(Item<double>{"Barry", 300.0});
    vec.push_back(Item<double>{"Curly", 400.0});

    for(const auto &item:vec){
        cout << "name : " << item.get_name() << " " << item.get_value() << endl;
    }



    My_pair<int,int> p1 {12,34};
    p1.print_class_member();
}