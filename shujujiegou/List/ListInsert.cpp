/*线性表的顺序存储的结构代码*/
#define MAXSIZE 20            /*存储空间初始分配量*/
typedef int ElemType;         /*ElemType类型根据实际情况而定，这里假设为int*/
typedef struct 
{
    ElemType data[MAXSIZE];   /*数组存储数据元素，最大值为MAXSIZE*/
    int length;               /*线性表长度*/
}SqList;

#define OK 1
#define ERROR 0
#define TURE 1
#define FALSE 0
typedef int Status;
/*Status是函数的类型，其值是函数结果状态代码，如OK等*/

/*初始条件：顺序线性表L已存在，1 <= i <= Listlength(L)*/
/*操作结果：在L中第i个位置之前插入新的数据元素e， L的长度加1*/
Status ListInsert(SqList *L, int i, ElemType e){
    if(L -> length == MAXSIZE) /*顺序线性表已经满*/
        return ERROR;
    if(i < 1 || i > L -> length + 1)/*当i不在范围内时*/
        return ERROR;
    if(i <= L -> length)/*插入的数据不在表尾*/    
        {
            for (int k = L -> length - 1; k >= i - 1; k++)
                L -> data[k + 1] = L -> data[k];
        }
    L -> data[i - 1] = e;    /*将新元素插入*/
    L -> length++;
    return OK;
}/*
C++
// 向链表中插入元素
bool ListInsert(List *L, int i, ElemType e) {
    if (i < 1)
        return false;

    ListNode *newNode = new ListNode;
    newNode->data = e;
    newNode->next = nullptr;

    if (i == 1) {
        newNode->next = *L;
        *L = newNode;
    } else {
        ListNode *current = *L;
        int j = 1;
        while (current && j < i - 1) {
            current = current->next;
            j++;
        }
        if (!current)
            return false;
        newNode->next = current->next;
        current->next = newNode;
    }

    return true;
}
*/