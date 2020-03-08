#include <stdio.h>
#define maxSize 7
typedef struct {
    char data;
    int cur;
}component;
//���ṹ�����������з������ӵ�����������
void reserveArr(component *array);
//��ʼ����̬����
int initArr(component *array);
//�������в������ݣ�body��ʾ�����ͷ����������е�λ�ã�add��ʾ����Ԫ�ص�λ�ã�a��ʾҪ���������
void insertArr(component * array,int body,int add,char a);
//ɾ�������к����ַ�a�Ľ��
void deletArr(component * array,int body,char a);
//���Ҵ洢���ַ�elem�Ľ���������λ��
int selectElem(component * array,int body,char elem);
//�������е��ַ�oldElem��ΪnewElem
void amendElem(component * array,int body,char oldElem,char newElem);
//�������
void displayArr(component * array,int body);
//�ӱ���������ժ�����нڵ��ʵ�ֺ���
int mallocArr(component * array);
//��ժ�������Ľڵ����ӵ�����������
void freeArr(component * array,int k);

int main() {
    component array[maxSize];
    int body=initArr(array);
    printf("��̬����Ϊ��\n");
    displayArr(array, body);
  
    printf("�ڵ�3��λ���ϲ����㡮e��:\n");
    insertArr(array, body, 3,'e');
    displayArr(array, body);
  
    printf("ɾ��������Ϊ��a���Ľ��:\n");
    deletArr(array, body, 'a');
    displayArr(array, body);
  
    printf("����������Ϊ��e���Ľ���λ��:\n");
    int selectAdd=selectElem(array,body ,'e');
    printf("%d\n",selectAdd);
    printf("�����������Ϊ��e����Ϊ��h��:\n");
    amendElem(array, body, 'e', 'h');
    displayArr(array, body);
    return 0;
}
//������������
void reserveArr(component *array){
    for (int i=0; i<maxSize; i++) {
        array[i].cur=i+1;//��ÿ������������ӵ�һ��
        array[i].data=' ';
    }
    array[maxSize-1].cur=0;//�������һ�������α�ֵΪ0
}

//��ʼ����̬����
int initArr(component *array){
    reserveArr(array);
    int body=mallocArr(array);
    //����һ��������������ָ��ʹ��ָ�����������һ����㣬��Ϊ����Ϊ�գ����Ժ�ͷ����غ�
    int tempBody=body;
    for (int i=1; i<5; i++) {
        int j=mallocArr(array);//�ӱ����������ó����еķ���
        array[tempBody].cur=j;//������Ŀ��߷�����������������һ��������
        array[j].data='a'+i-1;//��������ķ������������ʼ��
        tempBody=j;//��ָ���������һ������ָ�����
    }
    array[tempBody].cur=0;//�µ��������һ������ָ������Ϊ0
    return body;
}

void insertArr(component * array,int body,int add,char a){
    int tempBody=body;
    for (int i=1; i<add; i++) {
        tempBody=array[tempBody].cur;
    }
    int insert=mallocArr(array);
    array[insert].cur=array[tempBody].cur;
    array[insert].data=a;
    array[tempBody].cur=insert;
  
}

void deletArr(component * array,int body,char a){
    int tempBody=body;
    //�ҵ���ɾ������λ��
    while (array[tempBody].data!=a) {
        tempBody=array[tempBody].cur;
        //��tempBodyΪ0ʱ����ʾ�������������˵��������û�д洢�����ݵĽ��
        if (tempBody==0) {
            printf("������û�д�����");
            return;
        }
    }
    //���е��ˣ�֤���иý��
    int del=tempBody;
    tempBody=body;
    //�ҵ��ý�����һ����㣬��ɾ������
    while (array[tempBody].cur!=del) {
        tempBody=array[tempBody].cur;
    }
    //����ɾ�������α�ֱ�Ӹ���ɾ��������һ�����
    array[tempBody].cur=array[del].cur;
  
    freeArr(array, del);
}

int selectElem(component * array,int body,char elem){
    int tempBody=body;
    //���α�ֵΪ0ʱ����ʾ�������
    while (array[tempBody].cur!=0) {
        if (array[tempBody].data==elem) {
            return tempBody;
        }
        tempBody=array[tempBody].cur;
    }
    return -1;//����-1����ʾ��������û���ҵ���Ԫ��
}

void amendElem(component * array,int body,char oldElem,char newElem){
    int add=selectElem(array, body, oldElem);
    if (add==-1) {
        printf("�޸���Ԫ��");
        return;
    }
    array[add].data=newElem;
}

void displayArr(component * array,int body){
    int tempBody=body;//tempBody׼��������ʹ��
    while (array[tempBody].cur) {
        printf("%c,%d ",array[tempBody].data,array[tempBody].cur);
        tempBody=array[tempBody].cur;
    }
    printf("%c,%d\n",array[tempBody].data,array[tempBody].cur);

}

//��ȡ����ռ�
int mallocArr(component * array){
    //����������ǿգ��򷵻ط���Ľ���±꣬���򷵻�0�����������һ�����ʱ���ý����α�ֵΪ0��
    int i=array[0].cur;
    if (array[0].cur) {
        array[0].cur=array[i].cur;
    }
    return i;
}
//��ժ�������Ľڵ����ӵ�����������
void freeArr(component * array,int k){
    array[k].cur=array[0].cur;
    array[0].cur=k;
}