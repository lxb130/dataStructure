#include <stdio.h>
int main()
{
    struct
    {
        char *name;  //姓名
        int num;     //学号
        int age;     //年龄
        char group;  //所在小组
        float score; //成绩
    } stu1 = {"Tom", 12, 18, 'A', 136.5}, *pstu = &stu1;

    printf("%s\n",pstu->name);
    return 0;
}