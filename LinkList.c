#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
typedef struct LinkList
{
    int data;
    struct LinkList *next;
} LinkList;

LinkList *initLinkListHead()
{
    LinkList *p = (LinkList *)malloc(sizeof(LinkList));
    LinkList *temp = p;
    for (int i = 1; i <= 5; i++)
    {
        LinkList *a = (LinkList *)malloc(sizeof(LinkList));
        a->data = i;
        a->next = NULL;
        temp->next = a;
        temp = temp->next;
    }

    return p;
}


void getElem(LinkList *p, int pos)
{
    LinkList *temp = p;
    while (temp->next)
    {
        temp = temp->next;
        if (temp->data == pos)
        {
            printf("%d\n", temp->data);
        }
    }
}
LinkList *deleteElem(LinkList *p, int pos)
{
    LinkList *temp = p;
    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
    }
    LinkList *del = temp->next;
    temp->next = temp->next->next;
    free(del);
    return p;
}

LinkList *insertElem(LinkList *p, int elem, int pos)
{
    LinkList *temp = p;
    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
    }
    LinkList *add = (LinkList *)malloc(sizeof(LinkList));
    add->data = elem;
    add->next = temp->next;
    temp->next = add;
    return p;
}
void display(LinkList *p)
{
    LinkList *temp = p;
    while (temp->next)
    {
        temp = temp->next;
        printf("%d\t", temp->data);
    }
    printf("\n");
}

int main()
{
    printf("��ʼ������Ϊ\n");
    LinkList *p = initLinkListTail();
    display(p);
    deleteElem(p, 2);
    display(p);
    insertElem(p, 8, 2);
    display(p);
    // getElem(p, 3);
    return 0;
}