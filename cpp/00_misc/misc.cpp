#include <iostream>
using namespace std;

void test_reference() {
    int a = 10;
    int &p =a;
    cout << &p << " " << &a<< endl;
    cout << p << " " << a<< endl;
}

int main() {
    test_reference();
}