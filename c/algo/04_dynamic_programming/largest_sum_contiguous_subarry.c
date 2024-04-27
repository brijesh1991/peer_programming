#include <stdio.h>
//https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

void driver ();
void lscs(int *arr ,int size);

//Largest sum contguous subarray
void lscs(int *arr ,int size){
    for(int i =0;i<size;i++){
        printf("%4d\n",arr[i]);
    }

    int max_so_far = 0;
    int max_ending_now =0;
    int count =0;
    int start =0,end =0;

    for(int i =0 ;i <size;i++) {
        max_ending_now+= arr[i];
        if(max_so_far < max_ending_now) {
            max_so_far = max_ending_now;
            end=i;
        }
        if(max_ending_now <0){
            max_ending_now=0;
            start = i+1;
        }
    }
    printf("max so far %d count %d range(%d,%d)\n",
        max_so_far,count,start,end);
}




void main(){
    driver();

}


void driver () {
    int arr [8]={-2,-3,4,-1,-2,1,5,-3};
    int size =8;
    lscs(arr,size); 
}