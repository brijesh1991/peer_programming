#include "ll.h"

ll *reverse_k(ll *head, int size){
    ll *current= head;
    ll *next = NULL;
    ll *prev = NULL;
    int count =0;

    while(current != NULL && count < size){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if(next !=NULL)
        head->next =reverse_k(next,size);
    return prev;
    
}

ll *reverse_pair(ll *cur){
    
}

ll * reverse(ll *cur ) {
    ll *next,*prev=NULL;
    while(cur){
        next = cur->next;
        cur->next= prev;
        prev = cur;
        cur =next;
    }
    return prev;
}

ll* mergeLists(ll* head1, ll* head2) {
    if(!head1 && !head2)
        return NULL;
    if(head1 && !head2)
        return head1;
    if(!head1 && head2)
        return head2;
    if (head1->data < head2->data) {
        head1->next =  mergeLists(head1->next,  head2);
        return head1;
    } else {
        head2->next =  mergeLists(head1,  head2->next);
        return head2;
    }
}

int getNode(ll* llist, int positionFromTail) {
    ll *node = llist;
    int cnt =0;
    while(cnt <positionFromTail){
        printf("%d\n",node->data);
        node = node->next;
        cnt++;
    }
    ll *slow = llist;
    
    while(node->next!= NULL){
        node = node->next;
        slow = slow->next;
    }
    return slow->data;
}

int check_palindrome(ll * list) {
    ll *sec_half = list;
    ll *fast = list;
    int len , half_len=0;

    len = get_ll_len(list);
    printf("len %d\n",len);
    while(fast->next && fast->next->next) {
        fast  = fast->next->next;
        sec_half = sec_half->next;
        printf("%d \t %d\n",fast->data, sec_half->data );
    }
    if (len%2) {
        sec_half = sec_half->next;
        printf("%d\n",sec_half->data);
    }

    half_len= (int)(len/2);
    ll *rev = reverse(sec_half);
    for(int i=0;i< half_len;i++){
        printf("%d %d\n", list->data, rev->data);
        if (list->data !=rev->data){
            printf("Not a palindrome\n");
            return -1;
        }
        list = list->next;
        rev = rev->next;
    }
    printf("Valid palindrome sequence\n");
    return 0;
}