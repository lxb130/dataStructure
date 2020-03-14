#include <stdio.h>
#include <stdlib.h>
#define TElemType int

int rear = 0, front = 0;

//构造结点的结构体
typedef struct BiTNode
{
    TElemType data;                  //数据域
    struct BiTNode *lchild, *rchild; //左右孩子指针
} BiTNode, *BiTree;
//初始化树的函数
void CreateBiTree(BiTree *T)
{
    *T = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->data = 1;
    (*T)->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->rchild = (BiTNode *)malloc(sizeof(BiTNode));

    (*T)->lchild->data = 2;
    (*T)->lchild->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild->data = 5;
    (*T)->lchild->rchild->lchild = NULL;
    (*T)->lchild->rchild->rchild = NULL;
    (*T)->rchild->data = 3;
    (*T)->rchild->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->rchild->lchild->data = 6;
    (*T)->rchild->lchild->lchild = NULL;
    (*T)->rchild->lchild->rchild = NULL;
    (*T)->rchild->rchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->rchild->rchild->data = 7;
    (*T)->rchild->rchild->lchild = NULL;
    (*T)->rchild->rchild->rchild = NULL;
    (*T)->lchild->lchild->data = 4;
    (*T)->lchild->lchild->lchild = NULL;
    (*T)->lchild->lchild->rchild = NULL;
}

//模拟操作结点元素的函数，输出结点本身的数值
void displayElem(BiTNode *elem)
{
    printf("%d ", elem->data);
}

//层序遍历

/*

定义一个二叉树 队列（数组实现）

1.根节点入队
2.根节点出队，同时根节点的左右孩子节点入队


*/

//入队函数
void EnQueue(BiTree *a, BiTree node)
{
    a[rear++] = node;
}

//出队函数
BiTree DeQueue(BiTree *a)
{

    return a[front++];
}

//打印节点
//输出函数
void displayNode(BiTree node)
{
    printf("%d ", node->data);
}

int main()
{
    //创建二叉树
    BiTree tree;
    CreateBiTree(&tree);

    //定义二叉树队列(数组实现)
    BiTree a[20];

    //根节点入队
    EnQueue(a, tree);

    while(rear){

    }
    return 0;
}