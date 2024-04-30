/*线性表的单链表存储结构*/
typedef int ElemType;         /*ElemType类型根据实际情况而定，这里假设为int*/
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;
typedef struct Node *LinkList;/*定义LinkList*/
