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
/*�����������L�е�i�����֮ǰ�����µ�����Ԫ��e, L�ĳ��ȼ�1*/
bool ListInsert(LinkList *L, int i, ElemType e){
    int j;
    LinkList p, s;
    p = *L;
    j = 1;
    while(p && j < i){/*Ѱ�ҵ�i - 1�����*/
        p = p -> next;
        j++;
    }
    if(!p || j > i)
        return false;/*��i���ڵ㲻����*/
    s = (LinkList)malloc(sizeof(Node));/*�����µĽ��(C���Ա�׼����malloc)*/
    s -> data = e;
    s -> next = p -> next;      /*��p�ĺ�̽�㸳ֵ��s�ĺ��*/
    p -> next = s;              /*��s��ֵ��p�ĺ��*/
    return true;

}