#include <stdio.h>

int count = 0;

int notDanger(int row, int j, int (*chess)[8])
{
    int i, k, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0;

    //�ж��з���
    for (i = 0; i < 8; i++)
    {
        if (*(*(chess + i) + j) != 0)
        {
            flag1 = 1;
            break;
        }
    }

    //�ж�����
    for (i = row, k = j; i >= 0 && k >= 0; i--, k--)
    {
        if (*(*(chess + i) + k) != 0)
        {
            flag2 = 1;
            break;
        }
    }
    //�ж�����
    for (i = row, k = j; i < 8 && k < 8; i++, k++)
    {
        if (*(*(chess + i) + k) != 0)
        {
            flag3 = 1;
            break;
        }
    }

    //�ж�����
    for (i = row, k = j; i >= 0 && k < 8; i--, k++)
    {
        if (*(*(chess + i) + k) != 0)
        {
            flag4 = 1;
            break;
        }
    }

    //�ж�����
    for (i = row, k = j; i < 8, k >= 0; i++, k--)
    {
        if (*(*(chess + i) + k) != 0)
        {
            flag5 = 1;
            break;
        }
    }

    if (flag1 || flag2 || flag3 || flag4 || flag5)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void EightQueen(int row, int n, int (*chess)[8])
{
    int i = 0, j = 0;
    int chess2[8][8];

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            chess2[i][j] = chess[i][j];
        }
    }

    if (row == 8)
    {
        printf("�� %d ��\n", count + 1);
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 8; j++)
            {
                printf("%d  ", *(*(chess2 + i) + j));
            }
            printf("\n");
        }
        printf("\n");
        count++;
    }
    else
    {
        for (j = 0; j < n; j++)
        {
            if (notDanger(row, j, chess))
            {
                for (i = 0; i < 8; i++)
                {
                    *(*(chess2 + row)+i) = 0;
                }
                *(*(chess2 + row)+j) = 1;
                EightQueen(row + 1, n, chess2);
            }
        }
    }
}






int main()
{

    //��ӡһ��8 �� 8 ������,0 ��ʾû�лʺ�1 ��ʾ��һ���ʺ�
    //��ʼ������
    int chess[8][8];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            chess[i][j] = 0;
        }
    }

    EightQueen(0, 8, chess);
}