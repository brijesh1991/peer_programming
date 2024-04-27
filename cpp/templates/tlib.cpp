#include "tlib.h"


using namespace std;

template <typename T>
T square (T x) {
    return x *x;
}


void squareCb()
{
    cout << square(5) << endl;
    cout << square(5.5) << endl;
}
