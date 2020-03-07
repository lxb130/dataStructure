#include <stdio.h>
#include <stdlib.h>

typedef struct LinkStack
{
    int data;
    struct LinkStack *next;

} LinkStack;

LinkStack *push(LinkStack *stack, int data)
{
    LinkStack *temp = (LinkStack *)malloc(sizeof(LinkStack));
    temp->data = data;
    temp->next = stack;
    stack = temp;
    return stack;
}

LinkStack *pop(LinkStack *stack)
{
    if (stack)
    {
        LinkStack *p = stack;
        stack = stack->next;
        printf("弹出的元素为%d\t", p->data);
        if (stack)
        {
            printf("此时栈顶元素为%d\n", stack->data);
            return stack;
        }
        else
        {
            printf("栈已空\n");
            return stack;
        }
    }
    return stack;
}
int main()
{
    LinkStack *stack = NULL;
    stack=push(stack, 1);
    stack=push(stack, 2);
    stack=push(stack, 3);
    stack=push(stack, 4);
    stack=push(stack, 5);
    stack=pop(stack);
    stack=pop(stack);
    stack=pop(stack);
    stack=pop(stack);
    return 0;
}