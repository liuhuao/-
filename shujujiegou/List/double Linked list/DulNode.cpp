/*双向链表的储存结构*/
typedef int ElemType;  
typedef struct DulNode
{
    ElemType data;
    struct DulNode *prior; /*直接前驱指针*/
    struct DulNode *next; /*直接后驱指针*/
};
