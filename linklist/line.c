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

int getElem(line *list, int elem)
{
    line *head = list;
    while (head)
    {
        if (head->data == elem)
        {
            printf("%d\n", head->data);
        }

        head = head->next;
    }
    return -1;
}

line *insertLine(line *head, int data, int add)
{
    //�½�������Ϊdata�Ľ��
    line *temp = (line *)malloc(sizeof(line));
    temp->data = data;
    temp->prior = NULL;
    temp->next = NULL;
    //���뵽����ͷ��Ҫ���⿼��
    if (add == 1)
    {
        temp->next = head;
        head->prior = temp;
        head = temp;
    }
    else
    {
        line *body = head;
        //�ҵ�Ҫ����λ�õ�ǰһ�����
        for (int i = 1; i < add - 1; i++)
        {
            body = body->next;
        }
        //�ж�����Ϊ�棬˵������λ��Ϊ����β
        if (body->next == NULL)
        {
            body->next = temp;
            temp->prior = body;
        }
        else
        {
            body->next->prior = temp;
            temp->next = body->next;
            body->next = temp;
            temp->prior = body;
        }
    }
    return head;
}

line *deleteLine(line *list, int data)
{
    line *head = list;
    while (head)
    {
        if (head->data == data)
        {
            head->prior->next = head->next;
            head->next->prior = head->prior;
            free(head);
        }
        head = head->next;
    }
    return list;
}

line *updateElem(line *list, int pos, int newElem)
{
    line *head = list;
    for (int i = 1; i < pos; i++)
    {
        head = head->next;
    }
    head->data = newElem;
    return list;
}
int main()
{
    //����һ��ͷָ��
    line *head = NULL;
    //��������������
    head = initLine(head);
    //��������õ�����
    display(head);
    // getElem(head, 2);
    // head = insertLine(head, 8, 1)
    // display(head);
    // head = insertLine(head, 9, 5);
    // display(head);
    // head = deleteLine(head, 9);
    // display(head);
    head = updateElem(head, 4, 10);
    display(head);
    return 0;
}