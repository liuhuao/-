/*���Ա�ĵ�����洢�ṹ*/
#include <time.h>
#include <stdlib.h>
typedef int ElemType;         /*ElemType���͸���ʵ������������������Ϊint*/
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;
typedef struct Node *LinkList;/*����LinkList*/


/*�������n��Ԫ�ص�ֵ����������ͷ�ӵ�ĵ������Ա�L(β�巨)*/
void CreateListTail(LinkList *L, int n){
    LinkList p, r;
    int i;
    srand(time(0));                     /*��ʼ���������*/
    *L = (LinkList)malloc(sizeof(Node));/*�������Ա�*/
    r = *L;                             /*rΪָ��β���Ľ��*/
    for(i = 0; i < n; i++){
        p = (Node*)malloc(sizeof(Node));/*�����½��*/
        p -> data = rand() % 100 + 1;   /*�������100���ڵ�����*/
        r -> next = p;                  /*����β�ն˽���ָ��ָ���½��*/
        r = p;                          /*����ǰ���½�㶨��Ϊ��β�ն˽��*/
    }
    r ->next = NULL;                    /*��ʾ��ǰ�������*/
}