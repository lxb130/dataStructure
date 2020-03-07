#include <stdio.h>
#include <stdlib.h>
typedef struct Link
{
    int data;
    struct Link *next;
} Link;

int main()
{

    Link *p = (Link *)malloc(sizeof(Link)); //创建一个头结点
    p->data = 1;

    printf("p->data的值为%d\n", p->data);
    printf("p->next的值为%d\n", p->next);

    Link *a = (Link *)malloc(sizeof(Link)); //创建一个头结点
    a->data = 2;
    printf("a->data的值为%d\n", a->data);
    printf("a->next%d\n", a->next);
    p->next = a;
    printf("a的地址为%d\n", a);
    printf("p->data的值为%d\n", p->data);
    printf("p->next的值为%d\n", p->next);

    p = a;
    printf("p->data的值为%d\n", p->data);
    printf("p->next的值为%d\n", p->next);

    p->data = 3;
     printf("a的地址为%d\n", a);
    printf("a->data的值为%d\n", a->data);
    return 0;
}
