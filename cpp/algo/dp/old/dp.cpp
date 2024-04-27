#include "dp.h"

int maxContSubsequence(int arr[], int n){
    int max_sum=arr[0], max_so_far=0,start =0,end =0;;
    //max_sum =a[0];
    for (int i=0;i<n;i++){
        max_sum += arr[i];

        if(max_sum<0){
            max_sum =0;
            start = i+1;
        }
        if(max_so_far < max_sum){
            max_so_far = max_sum;
            end=i;
        }
    }
    cout << "start: " << start << " end: " << end <<endl;
    return max_sum;
}


int maxContSubsequenceNonconsequent(int arr[], int n){
    int marr[n];
    for(int i =0;i<n;i++)
        marr[i]=0;
    marr[0]=arr[0];
    marr[1]= max(arr[0],arr[1]);

    for(int i=2;i<n;i++){
        marr[i]=max(arr[i]+marr[i-2], marr[i-1]);
    }
    cout << "Sum non consequent "  << marr[n-1]<< endl;
    return marr[n-1];
}


int maxContSubsequenceNonthreeconsequent(int arr[], int n){
    int marr[n];
    for(int i =0;i<n;i++)
        marr[i]=0;
    marr[0]=arr[0];
    marr[1]= arr[0]+arr[1];
    marr[2]= max(marr[1],max(arr[1]+arr[2],arr[0]+arr[2]));

    for(int i=3;i<n;i++){
        marr[i]=max(marr[i-1],max(arr[i]+marr[i-2],  arr[i] + arr[i - 1] + marr[i - 3]));
    }
    cout << "Sum non consequent "  << marr[n-1]<< endl;
    return marr[n-1];
}


int maxIncreasingSum(int a[],int n){
    int marr[n];

    for(int i=0;i< n;i++){
        marr[i]= a[i];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j]<a[i] && (marr[i] < marr[j]+a[i])){
                marr[i] = marr[j]+a[i];
            }
            cout << marr[j] << " ";
        }
        cout << endl;
    }


    for(int i=0;i<n;i++)
        cout << marr[i] << " " ;
        return 1;
}


int maxIncreasingSubsequence(int a[],int n){
    int marr[n];

    for(int i=0;i< n;i++){
        marr[i]= 1;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j]<a[i] && (marr[i] < marr[j]+1)){
                marr[i] = marr[j]+1;
            }
            cout << marr[j] << " ";
        }
        cout << endl;
    }
    for(int i=0;i<n;i++)
        cout << marr[i] << " " ;

    return 1;
}



bool subsetSum(int a[],int n,int sum){
    if (sum ==0)
        return true;
    if( sum !=0 && n ==0)
        return false;

    return (subsetSum(a,n-1,sum)|| subsetSum(a,n-1,sum-a[n-1]));

}




int editDist(string str1, string str2, int m, int n)
{
    // Create a table to store results of subproblems
    int dp[m+1][n+1];

    // Fill d[][] in bottom up manner
    for (int i=0; i<=m; i++)
    {
        cout << str1[i] << " ";
        for (int j=0; j<=n; j++)
        {
            if(i==0)
                cout << str2[j] << " " ;
            // If first string is empty, only option is to
            // insert all characters of second string
            if (i==0)
                dp[i][j] = j;  // Min. operations = j

            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j==0)
                dp[i][j] = i; // Min. operations = i

            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1];
                cout << dp[i][j] << " ";
            }

            // If the last character is different, consider all
            // possibilities and find the minimum
            else{
                dp[i][j] = 1 + min(min(dp[i][j-1],  // Insert
                                   dp[i-1][j]),  // Remove
                                   dp[i-1][j-1]); // Replace
                 cout << dp[i][j] << " " ;
            }
        }
        cout << endl;
    }

    return dp[m][n];
}



int longestPalindromeSubsequence(string st, int i , int j){
    if(i ==j)
        return 1;
    if (st[i]== st[j] && (i+1)==j)
        return 2;
    if(st[i] ==st[j])
    {
        return longestPalindromeSubsequence(st,i+1, j-1)+2;
    }

    return max(longestPalindromeSubsequence(st,i+1,j), longestPalindromeSubsequence(st,i,j-1)) ;
}
