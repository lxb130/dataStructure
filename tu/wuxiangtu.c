#include <stdio.h>

typedef char VertexType; //�������������
typedef int EdgeType;    //����Ȩֵ����
#define MAXVEX 20        //����������

typedef struct
{
    VertexType vexs[MAXVEX];      //�����
    EdgeType arc[MAXVEX][MAXVEX]; //�ڽӾ���
    int numVertexes;              //ͼ�е�ǰ�Ķ������
    int numEdges;                 //ͼ�е�ǰ�Ķ������
} MGraph;

//��������ͼ
void createDN(MGraph *G)
{

    int i, j, k;
    printf("�����붥�����ͱ���\n");
    scanf("%d,%d", &G->numVertexes, &G->numEdges);

    for (i = 0; i < G->numVertexes; i++)
    {
        scanf("%d", &(G->vexs[i]));
    }
    //��ʼ���ڽӾ���5,5
    for (i = 0; i < G->numVertexes; i++)
    {
        for (j = 0; j < G->numVertexes; j++)
        {
            G->arc[i][j] = 0;
        }
    }

    //�����(vi,vj)
    for (k = 0; k < G->numEdges; k++)
    {
        scanf("%d,%d", &i, &j);
        G->arc[i][j] = 1;
        G->arc[j][i] = 1;
    }
}

//��������ͼ
void createDG(MGraph *G)
{

    int i, j, k;
    printf("�����붥�����ͱ���\n");
    scanf("%d,%d", &G->numVertexes, &G->numEdges);

    for (i = 0; i < G->numVertexes; i++)
    {
        scanf("%d", &(G->vexs[i]));
    }
    //��ʼ���ڽӾ���5,5
    for (i = 0; i < G->numVertexes; i++)
    {
        for (j = 0; j < G->numVertexes; j++)
        {
            G->arc[i][j] = 0;
        }
    }

    //�����(vi,vj)
    for (k = 0; k < G->numEdges; k++)
    {
        scanf("%d,%d", &i, &j);
        G->arc[i][j] = 1;
    }
}

//�������
void PrintGrapth(MGraph G)
{
    int i, j;
    for (i = 0; i < G.numVertexes; i++)
    {
        for (j = 0; j < G.numVertexes; j++)
        {
            printf("%d ", G.arc[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    MGraph G;       //����һ��ͼ�ı���
   // createDN(&G);   //���ô��������������ַ����
    createDG(&G);
    PrintGrapth(G); //���ͼ�Ķ��׾���
    return 0;
}