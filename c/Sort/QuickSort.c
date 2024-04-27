//https://www.geeksforgeeks.org/quick-sort/?ref=gcse
#include <stdio.h>

int findpivot(int *arr, int low , int high) {
    return 0;
}
void quicksort (int *arr , int low, int high) {
    if ( low < high) {
        int pi = findpivot(arr, low,high);
        quicksort(arr,low, pi-1);
        quicksort(arr, pi+1,high);
    }
} 


int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int len = sizeof(arr)/sizeof(int);
    printf("%d   \n\n",len);
    return 0;

} 