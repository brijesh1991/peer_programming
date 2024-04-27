#include <stdio.h>
#include <stdlib.h>

void driver() {
    int arr[] = {100, 180, 260, 310,
                    40, 535, 695};
    int len= sizeof(arr)/sizeof(int);
    int profit =0;

    printf("array_size %d\n",len);

    for(int i=1;i<len;i++) {
        if (arr[i] > arr[i-1])
            profit+=arr[i]-arr[i-1];
    }

    printf("Profit %d\n",profit);
}

int main() {
    driver();   
    return 0;
}