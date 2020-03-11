#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;

//Link (0) :��ʾָ�����Һ��ӵ�ָ��
//Thread (1) :��ʾָ��ǰ����̵�����
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

//ʼ��ָ��ǰһ������
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

//ģ��������Ԫ�صĺ����������㱾�����ֵ
void displayElem(BinThrNode *elem)
{
    printf("%c ", elem->data);
}

//�������
void PreOrderTraverse(BinThrThree T)
{
    if (T)
    {
        displayElem(T);              //���ò���������ݵĺ�������
        PreOrderTraverse(T->lchild); //���ʸý�������
        PreOrderTraverse(T->rchild); //���ʸý����Һ���
    }
    //������Ϊ�գ�������һ��
    return;
}

//����ʵ��ͷָ��
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

//����������������ǵݹ�

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