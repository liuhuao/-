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

//��ȡԪ�ز���
/*��ʼ������˳�����Ա�L�Ѵ��ڣ� 1 <= i <= LiseLenth(L)*/
/*�����������e����L�е�i������Ԫ�ص�ֵ*/
Status GetElem(SqList L, int i, ElemType *e){
    if(L.length ==  0 || i < 1 || i > L.length)
        return ERROR;
    *e = L.data[i - 1];
    return OK;
}
/*C++
// ��ȡ�����е� i ��Ԫ�ص�ֵ
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
