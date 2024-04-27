#include "ll.h"

int driver_palindrome() {
    int lst[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int len =sizeof(lst)/sizeof(int);
    ll *head= NULL;

    printf("size : %d\n",len);

    for(int i=0;i<len;i++){
        //printf("Inserting %d\n",lst[i]);
        insert_at_end(&head,lst[i]);
    }
    printf("forward list\n");
    print_ll(head);

    check_palindrome(head);

    int lst2[]={1,2,3,4,5,6,7,8,7,6,5,4,3,2,1};
    len =sizeof(lst2)/sizeof(int);
    head= NULL;

    printf("size : %d\n",len);

    for(int i=0;i<len;i++){
        //printf("Inserting %d\n",lst[i]);
        insert_at_end(&head,lst2[i]);
    }
    printf("forward list\n");
    print_ll(head);

    check_palindrome(head);
}

int driver_reverse(){
    int lst[]={1,2,3,4,5,6,7,8,9,10,11,12,13};
    int len =sizeof(lst)/sizeof(int);
    ll *head= NULL;

    printf("size : %d\n",len);

    for(int i=0;i<len;i++){
        //printf("Inserting %d\n",lst[i]);
        insert_at_end(&head,lst[i]);
    }
    printf("forward list\n");
    print_ll(head);


    ll *tail= NULL;
    for(int i=0;i<len;i++){
        //printf("Inserting %d from end \n",lst[i]);
        insert_at_begining(&tail,lst[i]);
    }
    printf("reverse list\n");
    print_ll(tail);


    ll *temp = reverse_k(head,3);
    printf("reverse %d list\n",2);
    print_ll(temp);
    return 0;
}

int main() {
    driver_palindrome();
    return 0;
}
