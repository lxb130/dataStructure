#include <stdio.h>
int main()
{
    struct
    {
        char *name;  //����
        int num;     //ѧ��
        int age;     //����
        char group;  //����С��
        float score; //�ɼ�
    } stu1 = {"Tom", 12, 18, 'A', 136.5}, *pstu = &stu1;

    printf("%s\n",pstu->name);
    return 0;
}