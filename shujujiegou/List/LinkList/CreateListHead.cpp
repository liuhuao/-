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


/*�������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��ͷ�巨��*/
void CreateListHead(LinkList *L, int n){
    LinkList p;
    int i;
    srand(time(0));             /*��ʼ���������*/
    *L = (LinkList)malloc(sizeof(Node));
    (*L) -> next = NULL;        /*�Ƚ���һ����ͷ���ĵ�����*/
    for(i = 0; i < n; i++){
        p = (LinkList)malloc(sizeof(Node)); /*�����½��*/
        p -> data = rand() % 100 + 1;       /*�������100���ڵ�����*/
        p -> next = (*L) -> next;
        (*L) -> next = p;                   /*���뵽��ͷ*/
    }
}