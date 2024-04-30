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

//获取元素操作
/*初始条件：顺序线性表L已存在， 1 <= i <= LiseLenth(L)*/
/*操作结果：用e返回L中第i个数据元素的值*/
Status GetElem(SqList L, int i, ElemType *e){
    if(L.length ==  0 || i < 1 || i > L.length)
        return ERROR;
    *e = L.data[i - 1];
    return OK;
}
/*C++
// 获取链表中第 i 个元素的值
bool GetElem(List L, int i, ElemType *e) {
    if (i < 1)
        return false;

    int j = 1;
    ListNode *current = L;
    while (current && j < i) {
        current = current->next;
        j++;
    }

    if (current && j == i) {
        *e = current->data;
        return true;
    } else {
        return false;
    }
}*/
