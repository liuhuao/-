/*线性表的单链表存储结构*/
#include <time.h>
#include <stdlib.h>
typedef int ElemType;         /*ElemType类型根据实际情况而定，这里假设为int*/
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;
typedef struct Node *LinkList;/*定义LinkList*/


/*随机产生n个元素的值，建立带表头结点的单链线性表L（头插法）*/
void CreateListHead(LinkList *L, int n){
    LinkList p;
    int i;
    srand(time(0));             /*初始化随机种子*/
    *L = (LinkList)malloc(sizeof(Node));
    (*L) -> next = NULL;        /*先建立一个带头结点的单链表*/
    for(i = 0; i < n; i++){
        p = (LinkList)malloc(sizeof(Node)); /*生程新结点*/
        p -> data = rand() % 100 + 1;       /*随机生成100以内的数字*/
        p -> next = (*L) -> next;
        (*L) -> next = p;                   /*插入到表头*/
    }
}