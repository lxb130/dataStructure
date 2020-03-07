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
        printf("����Ϊ��");
    }
    QNode *p = front->next;
    printf("���ӵ�Ԫ��Ϊ%d\n", p->data);
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
    queue = top = rear = initQueue(); //����ͷ���
    //������������ӽ�㣬ʹ��β�巨��ӵ�ͬʱ����βָ����Ҫָ����������һ��Ԫ��
    rear = enQueue(rear, 1);
    rear = enQueue(rear, 2);
    rear = enQueue(rear, 3);
    rear = enQueue(rear, 4);
    //�����ɣ���������Ԫ�ؿ�ʼ������
    rear = deQueue(top, rear);
    rear = deQueue(top, rear);
    rear = deQueue(top, rear);
    rear = deQueue(top, rear);
    rear = deQueue(top, rear);
    return 0;
}