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
    //新建数据域为data的结点
    line *temp = (line *)malloc(sizeof(line));
    temp->data = data;
    temp->prior = NULL;
    temp->next = NULL;
    //插入到链表头，要特殊考虑
    if (add == 1)
    {
        temp->next = head;
        head->prior = temp;
        head = temp;
    }
    else
    {
        line *body = head;
        //找到要插入位置的前一个结点
        for (int i = 1; i < add - 1; i++)
        {
            body = body->next;
        }
        //判断条件为真，说明插入位置为链表尾
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
    //创建一个头指针
    line *head = NULL;
    //调用链表创建函数
    head = initLine(head);
    //输出创建好的链表
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