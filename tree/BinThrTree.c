#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;

//Link (0) :表示指向左右孩子的指针
//Thread (1) :表示指向前驱后继的线索
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

//始终指向前一个变量
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

//模拟操作结点元素的函数，输出结点本身的数值
void displayElem(BinThrNode *elem)
{
    printf("%c ", elem->data);
}

//先序遍历
void PreOrderTraverse(BinThrThree T)
{
    if (T)
    {
        displayElem(T);              //调用操作结点数据的函数方法
        PreOrderTraverse(T->lchild); //访问该结点的左孩子
        PreOrderTraverse(T->rchild); //访问该结点的右孩子
    }
    //如果结点为空，返回上一层
    return;
}

//定义实现头指针
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

//中序遍历二叉树，非递归

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