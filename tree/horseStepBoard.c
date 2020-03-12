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
������ȱ�������x��y)Ϊλ������ tagΪ��Ǳ��� ��ÿ��һ��tag+1
*/

int TravelChessBoard(int x, int y, int tag)
{
    int x1 = x, y1 = y, flag = 0;
    int count = 0; // �����ڵ�λ�ã�ÿ�δ�λ��0����ʼ��</span>
    chess[x][y] = tag;
    if (tag == X * Y)
    {
        printChess(); //��ӡ����
        return 1;
    }
    //ȷ���ɹ��߳���һ��
    flag = nextxy(&x1, &y1, count);
    while (flag == 0 && count <= 7)
    {
        ++count; // ���в�ͨ�����л��ߵķ���
        flag = nextxy(&x1, &y1, count);
    }
    while (flag)
    {
        if (TravelChessBoard(x1, y1, tag + 1)) // �ɹ�����ȫ��
            return 1;
        // δ�ɹ����꣬�����������¿�ʼ��
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
        printf("��̤���̱���ʧ��\n");
    }

    finish = clock();
    printf("���γ�������һ����ʱ%f��\n\n", (double)(finish - start) / CLOCKS_PER_SEC);
    return 0;
}