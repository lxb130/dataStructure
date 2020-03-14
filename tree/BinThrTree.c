#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;

//Link (0) :?????????????????
//Thread (1) :?????????????????
typedef enum
{
    Link,
    Thread
} PointTertag;

typedef struct BinThrNode
{
    ElemType data;
    struct BinThrNode *lchild, *rchild;
    PointTertag ltag;
    PointTertag rtag;
} BinThrNode, *BinThrThree;

//??????????????
BinThrThree pre;

void createBinTree(BinThrThree *T)
{

    char c;
    scanf("%c", &c);
    if (' ' == c)
    {
        *T = NULL;
    }
    else
    {
        *T = (BinThrNode *)malloc(sizeof(BinThrNode));
        (*T)->data = c;
        (*T)->ltag = Link;
        (*T)->rtag = Link;
        createBinTree(&(*T)->lchild);
        createBinTree(&(*T)->rchild);
    }
}

void InThreading(BinThrThree T)
{
    if (T)
    {
        InThreading(T->lchild);

        if (!T->lchild)
        {
            T->ltag = Thread;
            T->lchild = pre;
        }

        if (!pre->rchild)
        {
            pre->rtag = Thread;
            pre->rchild = T;
        }
        pre = T;
        InThreading(T->rchild);
    }
}

//???????????????????????????????
void displayElem(BinThrNode *elem)
{
    printf("%c ", elem->data);
}

//???????
void PreOrderTraverse(BinThrThree T)
{
    if (T)
    {
        displayElem(T);              //???¨°??????????????????
        PreOrderTraverse(T->lchild); //????????????
        PreOrderTraverse(T->rchild); //?????????????
    }
    //???????????????????
    return;
}

//???????????
void InorderThreading(BinThrThree *p, BinThrThree T)
{
    (*p) = (BinThrNode *)malloc(sizeof(BinThrNode));
    (*p)->ltag = Link;
    (*p)->rtag = Thread;
    (*p)->rchild = (*p);
    if (!T)
    {
        (*p)->lchild = (*p);
    }
    else
    {
        (*p)->lchild = T;
        pre = *p;
        InThreading(T);
        pre->rchild = *p;
        pre->rtag = Thread;
        (*p)->rchild = pre;
    }
}

//???????????????????

void InorderTraverse(BinThrThree T)
{
    BinThrThree p = T->lchild;
    while (p != T)
    {
        while (p->ltag == Link)
        {
            p = p->lchild;
        }
        printf("%c  ", p->data);

        while (p->rtag == Thread && p->rchild != T)
        {
            p = p->rchild;
            printf("%c  ", p->data);
        }
        p = p->rchild;
    }
}

int main()
{
    BinThrThree P, tree;
    createBinTree(&tree);
    // PreOrderTraverse(tree);
    //  InThreading(tree);
    InorderThreading(&P, tree);
    InorderTraverse(P);
    return 0;
}