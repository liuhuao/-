/*线性表的单链表存储结构*/
typedef int ElemType;         /*ElemType类型根据实际情况而定，这里假设为int*/
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;
typedef struct Node *LinkList;/*定义LinkList*/


/*初始条件：顺序线性表L已存在， 1 <= i <= Listlength(L)*/
/*操作结果：用e返回L中第i个数据元素的值*/
bool GetElem(LinkList L, int i, ElemType *e){
    int j;
    LinkList p;     /*声明一指针p*/
    p = L -> next;  /*让p指向链表L的第一个结点*/
    j = 1;          /*j为计数器*/
    while (p && j < i)/*p不为空且计数器j还没有等于i时，循环继续*/
    {
        p = p -> next;  /*让p指向下一个节点*/
        j++;
    }
    if(!p || j > i)
        return false;   /*第i个结点不存在*/
    *e = p -> data;     /*取第i个结点的数据*/
    return true;

}