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


/*随机产生n个元素的值，建立带表头接点的单链线性表L(尾插法)*/
void CreateListTail(LinkList *L, int n){
    LinkList p, r;
    int i;
    srand(time(0));                     /*初始化随机种子*/
    *L = (LinkList)malloc(sizeof(Node));/*整个线性表*/
    r = *L;                             /*r为指向尾部的结点*/
    for(i = 0; i < n; i++){
        p = (Node*)malloc(sizeof(Node));/*生成新结点*/
        p -> data = rand() % 100 + 1;   /*随机生成100以内的数字*/
        r -> next = p;                  /*将表尾终端结点的指针指向新结点*/
        r = p;                          /*将当前的新结点定义为表尾终端结点*/
    }
    r ->next = NULL;                    /*表示当前链表结束*/
}