#include <stdio.h>
//Ԫ��elem��ջ
int push(int* a,int top,int elem){
    a[++top]=elem;
    return top;
}
//����Ԫ�س�ջ
int pop(int * a,int top){
    if (top==-1) {
        printf("��ջ");
        return -1;
    }
    printf("��ջԪ�أ�%d\n",a[top]);
    top--;
    return top;
}
int main() {
    int a[100];
    int top=-1;
    top=push(a, top, 1);
    top=push(a, top, 2);
    top=push(a, top, 3);
    top=push(a, top, 4);
    top=pop(a, top);
    top=pop(a, top);
    top=pop(a, top);
    top=pop(a, top);
    top=pop(a, top);
    return 0;
}