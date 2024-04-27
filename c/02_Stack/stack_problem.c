#include "stack.h"

void insert_at_bottom(stack *s,int data){
    if(isEmpty(s)) {
        push(&s,data);
    } else {
        int temp = peek(s);
        pop(&s);
        insert_at_bottom(s,data);
        push(&s,temp);
    }
}

stack *reverse_stack(stack *s)
{
    if (!isEmpty(s)){
        int data = peek(s);
        pop(&s);
        reverse_stack(s);
        insert_at_bottom(s,data);
    }
}

int compare_char(char c1, char c2){
    if ((c1 =='(' && c2== ')') ||
        (c1 =='[' && c2== ']') ||
        (c1 =='{' && c2== '}'))
        return 1;
    return 0;
}

int are_brackets_balanced(char expr[]) {
    char_stack *stack = NULL;
    int i=0;

    while(expr[i]!='\0'){
        if (expr[i] == '(' ||
            expr[i] == '['||
            expr[i] == '{'){
                char_push(&stack,expr[i]);
            }
        if (expr[i] == ')' ||
            expr[i] == ']'||
            expr[i] == '}'){
                if(!compare_char(char_pop(&stack),expr[i])){
                    printf("Not a matching brace expression\n");
                    return 0;
                }

            }
        i++;
    }
    if (char_pop(&stack) == '\0') {
        printf("its a balanced expression\n");
        return 1;
    }else {
        return 0;
    }
}