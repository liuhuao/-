/*���Ա�ĵ�����洢�ṹ*/
typedef int ElemType;         /*ElemType���͸���ʵ������������������Ϊint*/
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;
typedef struct Node *LinkList;/*����LinkList*/


/*��ʼ������˳�����Ա�L�Ѵ��ڣ� 1 <= i <= Listlength(L)*/
/*�����������e����L�е�i������Ԫ�ص�ֵ*/
bool GetElem(LinkList L, int i, ElemType *e){
    int j;
    LinkList p;     /*����һָ��p*/
    p = L -> next;  /*��pָ������L�ĵ�һ�����*/
    j = 1;          /*jΪ������*/
    while (p && j < i)/*p��Ϊ���Ҽ�����j��û�е���iʱ��ѭ������*/
    {
        p = p -> next;  /*��pָ����һ���ڵ�*/
        j++;
    }
    if(!p || j > i)
        return false;   /*��i����㲻����*/
    *e = p -> data;     /*ȡ��i����������*/
    return true;

}