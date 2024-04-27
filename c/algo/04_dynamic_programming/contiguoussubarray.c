#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//brv note not a correct implemenation
//https://www.geeksforgeeks.org/length-largest-subarray-contiguous-elements-set-1/?ref=rp
//

void driver();

int max (int n1,int n2){
    if ( n1 > n2 )
        return n1;
    else
        return n2;
}

int min (int n1,int n2){
    if ( n1 > n2 )
        return n2;
    else
        return n1;
}

void printcontiguousarray(int *arr , int n) 
{
    int max_len = 1;  // Initialize result
    for (int i=0; i<n-1; i++)
    {
        // Initialize min and max for all subarrays starting with i
        int mn = arr[i], mx = arr[i];
 
        // Consider all subarrays starting with i and ending with j
        for (int j=i+1; j<n; j++)
        {
            // Update min and max in this subarray if needed
            mn = min(mn, arr[j]);
            mx = max(mx, arr[j]);
 
            // If current subarray has all contiguous elements
            if ((mx - mn) == j-i){
                printf("%d %d\n",arr[i],arr[j]);
                max_len = max(max_len, mx-mn+1);
            }
        }
    }
    printf("max length %d\n",max_len);
    //return max_len;  // Return result
}


void main() {
    driver();
}

void driver(){
    //int arr[10] = {1, 56, 58, 57, 90, 92, 94, 93, 91, 45};
    int arr[10] = {14,12,11,20,13};
    int size =10;
    printcontiguousarray(arr,size);
}