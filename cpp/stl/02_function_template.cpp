#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

template <typename T>
T maxx(T a , T b) {
    return  (a >b)? a :b;
}

int main()
{
    cout << maxx(12,34)<<endl;
    cout << maxx(1123.231,10.123) << endl;
    return 0;
}