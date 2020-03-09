#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{

    int data;
    struct Node *next;
} Node, *Linklist;

Linklist create(int n)
{
    Linklist head = (Linklist)malloc(sizeof(Node));
    head->next = NULL;
    Linklist p = head;
    Linklist s;
    int i = 1;
    while (i <= n)
    {
        s = (Linklist)malloc(sizeof(Node));
        s->data = i++;
        p->next = s;
        p = s;
    }
    s->next = head->next;
    free(head);
    return s->next;
}

int main()
{
    int n = 41;
    int m = 3;
    Linklist p = create(n);
    Linklist temp;

    m %= n;
    while (p != p->next)
    {
        for (int i = 1; i < m - 1; i++)
        {
            p = p->next;
        }
        printf("%d->", p->next->data);
        temp = p->next;
        p->next = temp->next;
        free(temp);
        p = p->next;
    }
    printf("%d\n", p->data);
    return 0;
}