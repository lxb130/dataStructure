#include <stdio.h>
#include <stdlib.h>
#define TElemType int

int rear = 0, front = 0;

//������Ľṹ��
typedef struct BiTNode
{
    TElemType data;                  //������
    struct BiTNode *lchild, *rchild; //���Һ���ָ��
} BiTNode, *BiTree;
//��ʼ�����ĺ���
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

//ģ��������Ԫ�صĺ����������㱾�����ֵ
void displayElem(BiTNode *elem)
{
    printf("%d ", elem->data);
}

//�������

/*

����һ�������� ���У�����ʵ�֣�

1.���ڵ����
2.���ڵ���ӣ�ͬʱ���ڵ�����Һ��ӽڵ����


*/

//��Ӻ���
void EnQueue(BiTree *a, BiTree node)
{
    a[rear++] = node;
}

//���Ӻ���
BiTree DeQueue(BiTree *a)
{

    return a[front++];
}

//��ӡ�ڵ�
//�������
void displayNode(BiTree node)
{
    printf("%d ", node->data);
}

int main()
{
    //����������
    BiTree tree;
    CreateBiTree(&tree);

    //�������������(����ʵ��)
    BiTree a[20];

    //���ڵ����
    EnQueue(a, tree);

    while(rear){

    }
    return 0;
}