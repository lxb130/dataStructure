#include <stdio.h>

int push(int *arr, int top, int elem)
{
    top++;
    arr[top] = elem;
    return top;
}

int pop(int *arr, int top)
{
    if (top == -1)
    {
        printf("空栈'\n");
        return top;
    }

    printf("出栈的元素为%d\n", arr[top]);
    top--;
    return top;
}

int main()
{
    int arr[1000];
    int top = -1;
    top = push(arr, top, 1);
    top = push(arr, top, 2);
    top = push(arr, top, 3);
    top = push(arr, top, 4);
    top = push(arr, top, 5);

    top = pop(arr, top);
    top = pop(arr, top);
    top = pop(arr, top);
}