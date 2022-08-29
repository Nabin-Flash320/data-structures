

#include "stdio.h"
#include "stdlib.h"

typedef struct stack
{
    int value;
    struct stack *next;
}stack_t;

stack_t *top = NULL;

void push(int);
int pop();
void print_al();

int main()
{   
    push(10);
    push(100);
    push(200);
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    return 0;
}

void push(int val)
{
    stack_t *node = (stack_t*)malloc(sizeof(stack_t));
    node->next = top;
    node->value = val;
    top = node;
}

int pop()
{

    stack_t *node = (stack_t*)malloc(sizeof(stack_t));
    node = top;
    if(NULL == top || NULL == node)
    {
        printf("No stack");
        return -1;
    }

    top = top->next;
    int val = node->value;
    free(node);
    return val;

}
