#include <stdio.h>
#include <stdlib.h>
typedef struct Link
{
    int data;
    struct Link *next;
} Link;

int main()
{

    Link *p = (Link *)malloc(sizeof(Link)); //����һ��ͷ���
    p->data = 1;

    printf("p->data��ֵΪ%d\n", p->data);
    printf("p->next��ֵΪ%d\n", p->next);

    Link *a = (Link *)malloc(sizeof(Link)); //����һ��ͷ���
    a->data = 2;
    printf("a->data��ֵΪ%d\n", a->data);
    printf("a->next%d\n", a->next);
    p->next = a;
    printf("a�ĵ�ַΪ%d\n", a);
    printf("p->data��ֵΪ%d\n", p->data);
    printf("p->next��ֵΪ%d\n", p->next);

    p = a;
    printf("p->data��ֵΪ%d\n", p->data);
    printf("p->next��ֵΪ%d\n", p->next);

    p->data = 3;
     printf("a�ĵ�ַΪ%d\n", a);
    printf("a->data��ֵΪ%d\n", a->data);
    return 0;
}
