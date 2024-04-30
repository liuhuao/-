/*线性表的单链表存储结构*/
#include <iostream>
typedef int ElemType;         /*ElemType类型根据实际情况而定，这里假设为int*/
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;
typedef struct Node *LinkList;/*定义LinkList*/

/*
初始条件：顺序线性表L已存在
操作结果：将L重置为空表
*/
bool ClearList(LinkList *L){
    LinkList p, q;
    p = (*L) -> next;            /*p指向第一个结点*/
    while(p)                    /*遍历表*/
    {
        q = p -> next;
        free(p);
        p = q;
    }
    (*L) -> next = NULL;        /*头结点指针域为空*/
    return true;
}