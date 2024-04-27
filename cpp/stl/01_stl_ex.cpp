#include<iostream>
#include <vector>
#include<algorithm>
#include<iterator>

using namespace std;
int main()
{
   vector<int> vc= {1,5,8,3,2};
   cout << "raw string      : ";
   for (auto elem: vc)
        cout << elem << " ";
    
    cout << endl;

    // sort syntax
    cout << "sorted string   : ";
    sort(vc.begin(),vc.end());

    for (auto elem: vc)
        cout << elem << " ";
    cout << endl;

    // reverse syntax
    cout << "reversed string : ";
    reverse(vc.begin(), vc.end());

    for (auto elem: vc)
        cout << elem << " ";
    cout << endl;

    /* accumulate api is not working
    //calculate sum of a vector
    int sum = accumulate(vc.begin(),vc.end(),0)
    cout << "Sum : " << sum <<  endl;

    */
}