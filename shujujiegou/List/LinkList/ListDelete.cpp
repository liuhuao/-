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
/*操作结果：删除L的第i个结点，并用e返回其值, L的长度减1*/
bool ListInsert(LinkList *L, int i, ElemType *e){
    int j;
    LinkList p, q;
    p = *L;
    j = 1;
    while(p -> next && j < i){/*寻找第i - 1个结点*/
        p = p -> next;
        j++;
    }
    if(!(p -> next) || j > i)
        return false;/*第i个节点不存在*/
    q = p ->next;
    p -> next = q -> next;          /*将q的后记赋值给p的后继*/
    *e = q -> data;                 /*将q结点的数据给e*/
    free(q);                        /*让系统回收此结点，释放内存*/
    return true;
}