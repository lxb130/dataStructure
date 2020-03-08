#include <stdio.h>
#include <stdlib.h>

typedef struct line
{
    struct line *prior;
    int data;
    struct line *next;
} line;

line *initLine(line *head)
{
    head = (line *)malloc(sizeof(line));
    head->prior = NULL;
    head->next = NULL;
    head->data = 1;
    line *list = head;
    for (int i = 2; i <= 5; i++)
    {
        line *p = (line *)malloc(sizeof(line));
        p->next = NULL;
        p->data = i;

        list->next = p;
        p->prior = list;
        list = p;
    }
    return head;
}

void display(line *list)
{
    line *head = list;
    while (head)
    {
        if (head->next == NULL)
        {
            printf("%d\n", head->data);
        }
        else
        {
            printf("%d <-> ", head->data);
        }

        head = head->next;
    }
}

int main()
{
    //创建一个头指针
    line *head = NULL;
    //调用链表创建函数
    head = initLine(head);
    //输出创建好的链表
    display(head);
    //显示双链表的优点
    printf("链表中第 4 个节点的直接前驱是：%d", head->next->next->next->prior->data);
    return 0;
}