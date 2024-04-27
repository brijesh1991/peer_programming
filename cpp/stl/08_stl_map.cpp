#include "common.hpp"

void display(const map<string,int> &m){
    cout << "[ ";
    for(const auto &elem:m){
        cout <<elem.first << " : "<< elem.second<<" ";
    }
    cout << "]"<<endl;
}

void test1() {
    map<string,int> m {
        {"Larry",3},
        {"Moe",1},
        {"Curly",2}
    };
    display(m);

    m.insert(pair<string,int>("Anna",10));
    display(m);

    m.insert(make_pair("Joe",5));
    display(m);

    m["Frank"]=18;
    display(m);

    m["Frank"] +=10;
    display(m);

    m.erase("Anna");
    display(m);

    auto it =m.find("Larry");
    if (it != m.end()){
        cout << "found " << it->first <<" : " << it->second<<endl; 
    }
    m.clear();

    display(m);
}
int main() {
     test1();
    return 1;
}
