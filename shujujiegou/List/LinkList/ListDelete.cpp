/*���Ա�ĵ�����洢�ṹ*/
#include <stdlib.h>
typedef int ElemType;         /*ElemType���͸���ʵ������������������Ϊint*/
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;
typedef struct Node *LinkList;/*����LinkList*/


/*��ʼ������˳�����Ա�L�Ѵ��ڣ� 1 <= i <= Listlength(L)*/
/*���������ɾ��L�ĵ�i����㣬����e������ֵ, L�ĳ��ȼ�1*/
bool ListInsert(LinkList *L, int i, ElemType *e){
    int j;
    LinkList p, q;
    p = *L;
    j = 1;
    while(p -> next && j < i){/*Ѱ�ҵ�i - 1�����*/
        p = p -> next;
        j++;
    }
    if(!(p -> next) || j > i)
        return false;/*��i���ڵ㲻����*/
    q = p ->next;
    p -> next = q -> next;          /*��q�ĺ�Ǹ�ֵ��p�ĺ��*/
    *e = q -> data;                 /*��q�������ݸ�e*/
    free(q);                        /*��ϵͳ���մ˽�㣬�ͷ��ڴ�*/
    return true;
}