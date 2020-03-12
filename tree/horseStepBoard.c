#include <stdio.h>
#include <time.h>

#define X 8
#define Y 8

int chess[X][Y];

void printChess()
{
    int i, j;
    clock_t start, finish;
    start = clock();

    for (i = 0; i < X; i++)
    {
        for (j = 0; j < Y; j++)
        {
            printf("%2d\t", chess[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int nextxy(int *x,int *y,int count)
{
	switch(count)
	{
	case 0:
		if(*x+2<X && *y+1<Y && chess[*x+2][*y+1]==0)
		{
			*x+=2;
			*y+=1;
			return 1;
		}
		break;
	case 1:
		if(*x+2<X && *y-1>=0 && chess[*x+2][*y-1]==0)
		{
			*x+=2;
			*y-=1;
			return 1;
		}
		break;
	case 2:
		if(*x+1<X && *y-2>=0 && chess[*x+1][*y-2]==0)
		{
			*x+=1;
			*y-=2;
			return 1;
		}
		break;
	case 3:
		if(*x-1>=0 && *y-2>=0 && chess[*x-1][*y-2]==0)
		{
			*x-=1;
			*y-=2;
			return 1;
		}
		break;
	case 4:
		if(*x-2>=0 && *y-1>=0 && chess[*x-2][*y-1]==0)
		{
			*x-=2;
			*y-=1;
			return 1;
		}
		break;
	case 5:
		if(*x-2>=0 && *y+1<Y && chess[*x-2][*y+1]==0)
		{
			*x-=2;
			*y+=1;
			return 1;
		}
		break;
	case 6:
		if(*x-1>=0 && *y+2<Y && chess[*x-1][*y+2]==0)
		{
			*x-=1;
			*y+=2;
			return 1;
		}
		break;
	case 7:
		if(*x+1<X && *y+2<Y && chess[*x+1][*y+2]==0)
		{
			*x+=1;
			*y+=2;
			return 1;
		}
		break;
	default:
		break;
	}
	return 0;
}

/*
深度优先遍历，（x，y)为位置坐标 tag为标记变量 ，每走一步tag+1
*/

int TravelChessBoard(int x, int y, int tag)
{
    int x1 = x, y1 = y, flag = 0;
    int count = 0; // 对现在的位置，每次从位置0出开始走</span>
    chess[x][y] = tag;
    if (tag == X * Y)
    {
        printChess(); //打印棋盘
        return 1;
    }
    //确定成功走出第一步
    flag = nextxy(&x1, &y1, count);
    while (flag == 0 && count <= 7)
    {
        ++count; // 若行不通，则切换走的方向
        flag = nextxy(&x1, &y1, count);
    }
    while (flag)
    {
        if (TravelChessBoard(x1, y1, tag + 1)) // 成功走完全部
            return 1;
        // 未成功走完，换个方向重新开始走
        // x1 = x;
        // y1 = y;
        ++count;
        flag = nextxy(&x1, &y1, count);
        while (flag == 0 && count < 7)
        {
            ++count;
            flag = nextxy(&x1, &y1, count);
        }
    }
    if (flag == 0)
    {
        chess[x][y] = 0;
    }
    return 0;
}


int main()
{
    int i, j;
    clock_t start, finish;
    start = clock();

    for (i = 0; i < X; i++)
    {
        for (j = 0; j < Y; j++)
        {
            chess[i][j] = 0;
        }
    }

    if (!TravelChessBoard(2, 0, 1))
    {
        printf("马踏棋盘遍历失败\n");
    }

    finish = clock();
    printf("本次程序运行一共耗时%f秒\n\n", (double)(finish - start) / CLOCKS_PER_SEC);
    return 0;
}