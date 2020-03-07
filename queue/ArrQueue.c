#include <stdio.h>

int enQueue(int *a, int rear, int data)
{
    rear++;
    a[rear] = data;
    return rear;
}
void deQueue(int *a, int front)
{
    front++;
    int data = a[front];
    printf("出队的元素为%d", data);
}
int main()
{
    int arr[100];
    int front, rear;
    front = rear = 0;
    rear=enQueue(arr, rear, 1);
    rear=enQueue(arr, rear, 2);
    rear=enQueue(arr, rear, 3);
    rear=enQueue(arr, rear, 4);
    rear=enQueue(arr, rear, 5);
    deQueue(arr, front);
    return 0;
}