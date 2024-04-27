#include <stdio.h>
#include <math.h>

typedef struct __attribute__((__packed__)) tpc_{
    char c;
    double d;
    int i;
}tpc;


typedef struct test_t{
    unsigned int x: 2;
    unsigned int y: 2;
    unsigned int z: 2;
}test;

int test2()
{
    test t;
    t.x = 5;
    printf("value %d\n", t.x);
    return 0;
}

int test1(){
    tpc t1;
    printf("size %d\n", sizeof(tpc));
}


typedef struct struct3_{
    unsigned int x;
    unsigned int y:3;
    unsigned int z;
}struct3;

void test3(){
    struct3 ss;
    printf("size %d\n",sizeof(test3));
}


void test4(){
    int installment = 16000;
    float sum=0;
    for(int i =0;i<15;i++){
        sum+=(installment);
        sum*=1.1;
        printf("%3d : %20f\n",i,sum);
    }
}

int main(){
    //test1();
    //test2();
    //test3();
    test4();
    return 0 ;
}