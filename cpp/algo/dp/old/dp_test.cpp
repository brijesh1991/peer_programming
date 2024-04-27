#include "dp.h"

void maxContSubsequence_test(){
    int arr[] = {1,-3,4,-2,-1,6};
    int  n =6;
    cout << maxContSubsequence(arr,n);

}

void maxContSubsequenceNonconsequent_test(){
    int arr[]= {5, 5, 10, 100, 10, 5};
    int n =6;
    maxContSubsequenceNonconsequent(arr,n);
}


void maxContSubsequenceNonthreeconsequent_test(){
    int arr[]= {5, 5, 10, 100, 10, 5};
    int n =6;
    maxContSubsequenceNonthreeconsequent(arr,n);
}



void maxIncreasingSum_test(){
    int arr[]={1, 101, 2, 3, 100, 4,5};
    int n =7;
    maxIncreasingSum(arr,n);
}

void maxIncreasingSubsequence_test(){
    int arr[]={1, 101, 2, 3, 100, 4,5,6,7};
    int n =9;
    maxIncreasingSubsequence(arr,n);
}


void subsetSum_test()
{
    int arr[]={1, 101, 2, 3, 100, 4,5,6,7};
    int sum =409, n =9;
    bool ret = subsetSum(arr,n,sum);

    if(ret == true)
        cout << "subset exists" << endl;
    else
        cout << "subset does not exists" << endl;
}



void editDist_test()
{
    string st2 ="saturday";
    string st1 = "sunday";

    cout <<endl <<"number of operations: "<< editDist(st1,st2, st1.length(), st2.length())  <<endl;
}



void longestPalindromeSubsequence_test()
{
    string st = "geeksforgeeks";
    cout << "LPS: " << longestPalindromeSubsequence(st,0,st.length()-1);
}
