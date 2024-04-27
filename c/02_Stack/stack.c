#include "stack.h"

// main function
int main(void)
{
	struct Node *top = NULL;

	push(&top, 1);
	push(&top, 2);
	push(&top, 3);

	display(top);

	printf("\nTop element is %d\n", peek(top));

	pop(&top);
	pop(&top);

	display(top);

	printf("\nTop element is %d\n", peek(top));

	pop(&top);
	pop(&top);
	pop(&top);
	pop(&top);

	if (isEmpty(top))
		printf("\nStack is empty\n");
	else
		printf("\nStack is not empty\n");

	return 0;
}
