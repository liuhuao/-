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
/*操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1*/
Status ListDelete(SqList *L, int i, ElemType *e){
    int k;
    if(L -> length == 0)    /*线性表为空*/
        return ERROR;
    if(i < 1 || i > L -> length) /*删除位置不正确*/
        return ERROR;
    *e = L -> data[i - 1];    
    if(i < L -> length)        /*删除的位置不在最后*/
    {
        for (k = i; k < L -> length; k++)/*将删除位置后继元素前移*/
        {
            L -> data[k - 1] = L -> data[k];
        }
    }
    L -> length--;
    return OK;
}