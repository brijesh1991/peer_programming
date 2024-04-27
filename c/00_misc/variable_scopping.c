#include <stdio.h>
#include <stdlib.h>

/*
Testing global, static , read-only and local variable by checking 
address and value of initialized and uninitialized memory/variable
*/
int val1;
static int  val2;
int val11=1;
static int  val12=1;
char *ch1 = "testing";

int main() {
    int val3;
    static int val4;
    int val13=2;
    static int val14=2;
    char *ch2 = "testing2";


    printf("%p %p %p %p\n",&val1, &val2, &val3, &val4);
    printf("%d %d %d %d\n",val1, val2, val3, val4);
    printf("%p %p %p %p\n",&val11, &val12, &val13, &val14);
    printf("%d %d %d %d\n",val11, val12, val13, val14);
    printf("charstring %s %p\n",ch1,ch1);
    printf("charstring %s %p\n",ch2,ch2);
    ch2[2]='a';
    printf("charstring %s %p\n",ch2,ch2);
    return 0;
}