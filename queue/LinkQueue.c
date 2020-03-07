#include <stdio.h>
#include <stdlib.h>

typedef struct QNode
{
    int data;
    struct QNode *next;
} QNode;

QNode *initQueue()
{
    QNode *p = (QNode *)malloc(sizeof(QNode));
    p->next = NULL;
    return p;
}

QNode *enQueue(QNode *rear, int data)
{
    QNode *p = (QNode *)malloc(sizeof(QNode));
    p->data = data;
    p->next = NULL;
    rear->next = p;
    rear = p;
    return rear;
}

QNode *deQueue(QNode *front, QNode *rear)
{

    if (front->next == NULL)
    {
        printf("队列为空");
    }
    QNode *p = front->next;
    printf("出队的元素为%d\n", p->data);
    front->next = p->next;
    if (rear == p)
    {
        rear = p;
    }
    free(p);
    return rear;
}
int main()
{

    QNode *queue, *top, *rear;
    queue = top = rear = initQueue(); //创建头结点
    //向链队列中添加结点，使用尾插法添加的同时，队尾指针需要指向链表的最后一个元素
    rear = enQueue(rear, 1);
    rear = enQueue(rear, 2);
    rear = enQueue(rear, 3);
    rear = enQueue(rear, 4);
    //入队完成，所有数据元素开始出队列
    rear = deQueue(top, rear);
    rear = deQueue(top, rear);
    rear = deQueue(top, rear);
    rear = deQueue(top, rear);
    rear = deQueue(top, rear);
    return 0;
}