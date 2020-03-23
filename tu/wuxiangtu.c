#include <stdio.h>

typedef char VertexType; //顶点的数据类型
typedef int EdgeType;    //边上权值类型
#define MAXVEX 20        //顶点最大个数

typedef struct
{
    VertexType vexs[MAXVEX];      //顶点表
    EdgeType arc[MAXVEX][MAXVEX]; //邻接矩阵
    int numVertexes;              //图中当前的顶点个数
    int numEdges;                 //图中当前的顶点个数
} MGraph;

//构造无向图
void createDN(MGraph *G)
{

    int i, j, k;
    printf("请输入顶点数和边数\n");
    scanf("%d,%d", &G->numVertexes, &G->numEdges);

    for (i = 0; i < G->numVertexes; i++)
    {
        scanf("%d", &(G->vexs[i]));
    }
    //初始化邻接矩阵5,5
    for (i = 0; i < G->numVertexes; i++)
    {
        for (j = 0; j < G->numVertexes; j++)
        {
            G->arc[i][j] = 0;
        }
    }

    //输入边(vi,vj)
    for (k = 0; k < G->numEdges; k++)
    {
        scanf("%d,%d", &i, &j);
        G->arc[i][j] = 1;
        G->arc[j][i] = 1;
    }
}

//构造有向图
void createDG(MGraph *G)
{

    int i, j, k;
    printf("请输入顶点数和边数\n");
    scanf("%d,%d", &G->numVertexes, &G->numEdges);

    for (i = 0; i < G->numVertexes; i++)
    {
        scanf("%d", &(G->vexs[i]));
    }
    //初始化邻接矩阵5,5
    for (i = 0; i < G->numVertexes; i++)
    {
        for (j = 0; j < G->numVertexes; j++)
        {
            G->arc[i][j] = 0;
        }
    }

    //输入边(vi,vj)
    for (k = 0; k < G->numEdges; k++)
    {
        scanf("%d,%d", &i, &j);
        G->arc[i][j] = 1;
    }
}

//输出函数
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
    MGraph G;       //建立一个图的变量
   // createDN(&G);   //调用创建函数，传入地址参数
    createDG(&G);
    PrintGrapth(G); //输出图的二阶矩阵
    return 0;
}