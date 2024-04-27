#include <stdio.h>

/*
 *
 * Implement a bit array.
 *
 * A bit array is a space efficient array that holds a value of 1 or 0 at each index.
 *
 * init(size): initialize the array with size
 * set(i, val): updates index at i with val where val is either 1 or 0.
 * get(i): gets the value at index i.
 *
*/

/*
Note  for revision
1. validate boundary condition during setting
2. in case of set operation can we reduce the code within if/else block and unify the code


*/
typedef struct bit_array_t{
    int size;
    unsigned char *arr;
}bit_array;

bit_array * init(int size);
int set(bit_array *ba, int index , int val);
int get (bit_array *ba, int index);


bit_array * init(int size) {
    if( size <=0)
        return NULL;
    int num_bytes = size/8;

    if (size%8 > 0)
        num_bytes+=1;

    bit_array *ba = (bit_array *)calloc(1,sizeof(bit_array));

    if (ba == NULL)
        return NULL;
    
    ba->arr = (char *)calloc(num_bytes,sizeof(char));
    ba->size = size;

    return ba;
}
 
int set(bit_array *ba, int index, int val) {
    int byt, pos;
    unsigned char mask=0;
    byt = index/8;
    pos = index%8;
    printf("pos %d\n",index);
    if(val){
        mask = 1<<pos;
        printf("mask 0x%x\n",mask);
        printf("pre set 1 0x%x\n",ba->arr[byt]);
        ba->arr[byt]= ba->arr[byt] | mask;
        printf("post set 1 0x%x\n\n",ba->arr[byt]);
    } else {
        mask = 1<<pos;
        mask = ~mask;
        printf("mask 0x%x\n",mask);
        printf("pre set 0 0x%x\n",ba->arr[byt]);
        ba->arr[byt]= ba->arr[byt] & mask;
        printf("post set 0 0x%x\n\n",ba->arr[byt]);
    }
}

int get (bit_array *ba , int index) {
    int byt, pos;
    unsigned char mask=0;
    byt = index/8;
    pos = index%8;
    printf("pos %d\n",index);
    mask = 1 <<pos;
    if(ba->arr[byt] & mask)
        return 1;
    else 
        return 0;
}

int main() {

    bit_array *ptr = init(20);
    set(ptr,1,1);
    set(ptr,1,1);
    set(ptr,2,1);
    set(ptr,3,1);
    set(ptr,6,1);
    set(ptr,1,0);
    set(ptr,3,0);
    printf("get %d\n",get(ptr,0));
    printf("get %d\n",get(ptr,1));
    printf("get %d\n",get(ptr,2));
    printf("get %d\n",get(ptr,3)); 
    printf("get %d\n",get(ptr,4));
    printf("get %d\n",get(ptr,5));
    printf("get %d\n",get(ptr,6));
    printf("get %d\n",get(ptr,7));
    printf("get %d\n",get(ptr,8));


}
