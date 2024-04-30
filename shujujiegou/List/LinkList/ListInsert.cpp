/*线性表的单链表存储结构*/
#include <stdlib.h>
typedef int ElemType;         /*ElemType类型根据实际情况而定，这里假设为int*/
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;
typedef struct Node *LinkList;/*定义LinkList*/

/*初始条件：顺序线性表L已存在， 1 <= i <= Listlength(L)*/
/*操作结果：在L中第i个结点之前插入新的数据元素e, L的长度加1*/
bool ListInsert(LinkList *L, int i, ElemType e){
    int j;
    LinkList p, s;
    p = *L;
    j = 1;
    while(p && j < i){/*寻找第i - 1个结点*/
        p = p -> next;
        j++;
    }
    if(!p || j > i)
        return false;/*第i个节点不存在*/
    s = (LinkList)malloc(sizeof(Node));/*生成新的结点(C语言标准函数malloc)*/
    s -> data = e;
    s -> next = p -> next;      /*将p的后继结点赋值给s的后继*/
    p -> next = s;              /*将s赋值给p的后继*/
    return true;

}