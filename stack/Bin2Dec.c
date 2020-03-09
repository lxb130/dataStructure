#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_INIT_SiZE 20
#define STACKINCREMENT 10
typedef char ElemType;

typedef struct
{
    ElemType *top;
    ElemType *base;
    int StackSize;
} sqStack;

void initSqStack(sqStack *s)
{
    s->base = (ElemType *)malloc(STACK_INIT_SiZE * sizeof(ElemType));
    if (!s->base)
    {
        exit(0);
    }
    s->top = s->base;
    s->StackSize = STACK_INIT_SiZE;
}

void push(sqStack *s, ElemType e)
{
    if (s->top - s->base >= s->StackSize)
    {
        s->base = (ElemType *)realloc(s->base, (s->StackSize + STACKINCREMENT) * sizeof(ElemType));
        if (!s->base)
        {
            exit(0);
        }
    }
    *(s->top) = e;
    s->top++;
}

void pop(sqStack *s, ElemType *e)
{
    if (s->top == s->base)
    {
        return;
    }
    *e = *--(s->top);
}

int sqStackLen(sqStack s)
{
    return (s.top - s.base);
}
int main()
{
    ElemType c;
    sqStack s;
    int len, i, sum = 0;
    initSqStack(&s);
    scanf("%c", &c);
    while (c != '#')
    {
        push(&s, c);
        scanf("%c", &c);
    }
    getchar();
    len = sqStackLen(s);
    printf("栈的当前大小为%d\n", len);

    for (i = 0; i < len; i++)
    {
        pop(&s, &c);
        sum = sum + (c - 48) * pow(2, i);
    }
    printf("二进制转换为十进制为%d\n", sum);
    return 0;
}