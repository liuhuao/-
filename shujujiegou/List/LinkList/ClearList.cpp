/*���Ա�ĵ�����洢�ṹ*/
#include <iostream>
typedef int ElemType;         /*ElemType���͸���ʵ������������������Ϊint*/
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;
typedef struct Node *LinkList;/*����LinkList*/

/*
��ʼ������˳�����Ա�L�Ѵ���
�����������L����Ϊ�ձ�
*/
bool ClearList(LinkList *L){
    LinkList p, q;
    p = (*L) -> next;            /*pָ���һ�����*/
    while(p)                    /*������*/
    {
        q = p -> next;
        free(p);
        p = q;
    }
    (*L) -> next = NULL;        /*ͷ���ָ����Ϊ��*/
    return true;
}