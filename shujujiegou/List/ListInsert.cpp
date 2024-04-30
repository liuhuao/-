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
/*�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e�� L�ĳ��ȼ�1*/
Status ListInsert(SqList *L, int i, ElemType e){
    if(L -> length == MAXSIZE) /*˳�����Ա��Ѿ���*/
        return ERROR;
    if(i < 1 || i > L -> length + 1)/*��i���ڷ�Χ��ʱ*/
        return ERROR;
    if(i <= L -> length)/*��������ݲ��ڱ�β*/    
        {
            for (int k = L -> length - 1; k >= i - 1; k++)
                L -> data[k + 1] = L -> data[k];
        }
    L -> data[i - 1] = e;    /*����Ԫ�ز���*/
    L -> length++;
    return OK;
}/*
C++
// �������в���Ԫ��
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