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
    //����һ��ͷָ��
    line *head = NULL;
    //��������������
    head = initLine(head);
    //��������õ�����
    display(head);
    //��ʾ˫������ŵ�
    printf("�����е� 4 ���ڵ��ֱ��ǰ���ǣ�%d", head->next->next->next->prior->data);
    return 0;
}