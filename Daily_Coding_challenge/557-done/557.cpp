#include<bits/stdc++.h>

using namespace std;

int count_x_in_square_matrix_o_n(int n,int x){
    int count=0;
    if (n ==0 || x ==0 || x > n*n) 
        return 0;
    for(int i=1;i<=n;i++) {
        if ((x%i==0) && (x/i <=n)){
            count+=1;
            //cout <<i <<endl;
        }
    }
    return count;
}



int count_x_in_square_matrix_o_n_2(int n,int x){
    int count=0, i=1;
    if (n ==0 || x ==0 || x > n*n) 
        return 0;
    
    while (i*i <x) {
        if ((x%i==0) && (x/i <=n))
            count+=2;
        //cout <<i <<" " << count<<endl;
        i+=1;
        if (i*i ==x)
            count+=1;
    }
    return count;
}

int main()
{
    cout <<count_x_in_square_matrix_o_n_2(6,12)<<endl;
    return 0;
}