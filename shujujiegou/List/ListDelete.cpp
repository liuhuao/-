/*���Ա��˳��洢�Ľṹ����*/
#define MAXSIZE 20            /*�洢�ռ��ʼ������*/
typedef int ElemType;         /*ElemType���͸���ʵ������������������Ϊint*/
typedef struct 
{
    ElemType data[MAXSIZE];   /*����洢����Ԫ�أ����ֵΪMAXSIZE*/
    int length;               /*���Ա���*/
}SqList;

#define OK 1
#define ERROR 0
#define TURE 1
#define FALSE 0
typedef int Status;
/*Status�Ǻ��������ͣ���ֵ�Ǻ������״̬���룬��OK��*/

/*��ʼ������˳�����Ա�L�Ѵ��ڣ�1 <= i <= Listlength(L)*/
/*���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1*/
Status ListDelete(SqList *L, int i, ElemType *e){
    int k;
    if(L -> length == 0)    /*���Ա�Ϊ��*/
        return ERROR;
    if(i < 1 || i > L -> length) /*ɾ��λ�ò���ȷ*/
        return ERROR;
    *e = L -> data[i - 1];    
    if(i < L -> length)        /*ɾ����λ�ò������*/
    {
        for (k = i; k < L -> length; k++)/*��ɾ��λ�ú��Ԫ��ǰ��*/
        {
            L -> data[k - 1] = L -> data[k];
        }
    }
    L -> length--;
    return OK;
}