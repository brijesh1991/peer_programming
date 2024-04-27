#include "common.hpp"


void test11(vector<int> vec) {
     cout << "forward"<< endl;
     auto it = vec.begin();
     while( it != vec.end()){
         cout << *it << endl;
         it++;
     }
 }

void test12(vector<int> vec) {
    cout << "reverse" << endl;
    auto it = vec.rbegin();
    while( it != vec.rend()){
        cout << *it << endl;
        it++;
    }
}


void test13(vector<int> vec) {
    cout << "forward constant" << endl;
    auto it = vec.cbegin();
    while( it != vec.cend()){
        cout << *it << endl;
        it++;
    }
}

void test14(vector<int> vec) {
    cout << "reverse constant" << endl;
    auto it = vec.crbegin();
    while( it != vec.crend()){
        cout << *it << endl;
        it++;
    }
}

void test21(map<string,string> vec) {
    cout << "forward"<< endl;
    auto it = vec.begin();
    while( it != vec.end()){
        cout << it->first << " " << it->second << endl;
        it++;
    }
}

void test22(map<string,string>  vec) {
    cout << "reverse" << endl;
    auto it = vec.rbegin();
    while( it != vec.rend()){
        cout << it->first << " " << it->second << endl;
        it++;
    }
}


void test23(map<string,string>  vec) {
    cout << "forward constant" << endl;
    auto it = vec.cbegin();
    while( it != vec.cend()){
        cout << it->first << " " << it->second << endl;
        it++;
    }
}

void test24(map<string,string>  vec) {
    cout << "reverse constant" << endl;
    auto it = vec.crbegin();
    while( it != vec.crend()){
        cout << it->first << " " << it->second << endl;
        it++;
    }
}

void test31(set<char> vec) {
     cout << "forward"<< endl;
     auto it = vec.begin();
     while( it != vec.end()){
         cout << *it << endl;
         it++;
     }
 }

void test32(set<char> vec) {
    cout << "reverse" << endl;
    auto it = vec.rbegin();
    while( it != vec.rend()){
        cout << *it << endl;
        it++;
    }
}


void test33(set<char> vec) {
    cout << "forward constant" << endl;
    auto it = vec.cbegin();
    while( it != vec.cend()){
        cout << *it << endl;
        it++;
    }
}

void test34(set<char> vec) {
    cout << "reverse constant" << endl;
    auto it = vec.crbegin();
    while( it != vec.crend()){
        cout << *it << endl;
        it++;
    }
}

int main()
{
    vector<int> vec {21,222,13};
    list<int> lst {1,2,3,4};
    set<char> st  {'C','H','A','D'};
    map<string,string> mp {
        {"m1", "Master"},
        {"m2", "Intermediate"},
        {"m3", "Slave"}
    };
    vector<int>::iterator it1 = vec.begin();
    // auto it = vec.begin();
    list<string>::iterator it2;
    map<string,string>::iterator it3;
    set<char>::iterator it4;

    test11(vec);
    cout << endl;
    test12(vec);
    cout << endl;
    test13(vec);
    cout << endl;
    test14(vec);
    cout << endl;


    test21(mp);
    cout << endl;
    test22(mp);
    cout << endl;
    test23(mp);
    cout << endl;
    test24(mp);
    cout << endl;

    test31(st);
    cout << endl;
    test32(st);
    cout << endl;
    test33(st);
    cout << endl;
    test34(st);
    cout << endl;

    set<char> suits {'C','H','S','D'};
    auto it = suits.begin();
    while (it != suits.end()) {
        cout << *it<<endl;
        it++;
    }

    vector<int> vec2{11,22,33,44};
    vector<int>::reverse_iterator it5 = vec2.rbegin();
    cout << endl;
    while (it5 != vec2.rend()){
        cout << *it5 << endl;
        ++it5;
    }

    return 1;
}