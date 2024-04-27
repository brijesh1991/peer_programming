#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int tab[20][20];

int subset(int arr[], int n , int sum) {

    if (sum ==0)
        return 1;
    if(n <=0)
        return 0;

    if(tab[n-1][sum]!=-1)
        return tab[n-1][sum];
    
    if(arr[n-1]>sum){
        return tab[n-1][sum] = subset(arr,n-1,sum);
    } else {
        return tab[n-1][sum] = subset(arr,n-1,sum) || subset(arr,n-1,sum -arr[n-1]) ;
    }
}

bool isSubsetSum(int arr[], int n, int sum)
{
    // The value of subset[i][j] will be true if
    // there is a subset of set[0..j-1] with sum
    // equal to i
    bool subset[n + 1][sum + 1];
 
    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;
 
    // If sum is not 0 and set is empty,
    // then answer is false
    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;
 
    // Fill the subset table in bottom up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < arr[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= arr[i - 1])
                subset[i][j] = subset[i - 1][j]
                               || subset[i - 1][j - arr[i - 1]];
        }
    }
 
    /*   // uncomment this code to print table
     for (int i = 0; i <= n; i++)
     {
       for (int j = 0; j <= sum; j++)
          printf ("%4d", subset[i][j]);
       cout <<"\n";
     }*/
 
    return subset[n][sum];
}
 
void print_matrix(){
    for (int i=0 ;i<20;i++){
        if (i <10){
            cout <<"  "<< i <<" ";
        }else {
            cout<<" " << i <<" ";
        }
    }
    cout <<endl;
    for (int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if (tab[i][j] == -1)
                cout<<" " <<tab[i][j]<< " ";
            else
                cout <<"  " <<tab[i][j]<< " ";
        }
        cout << endl;
    }
}


int main() {
    int arr[] = {1,5,3,7,4};
    /*
    memset(tab, -1, sizeof(tab));
    print_matrix();
    subset(arr,5,12);
    cout <<"finals"<<endl;
    print_matrix();
    */
    if(isSubsetSum(arr,5,12))
        cout << "found one subset with corrsponding sum"<<endl;
    else 
        cout << "No matching subset with corrsponding sum"<<endl;

    return 0;
}
