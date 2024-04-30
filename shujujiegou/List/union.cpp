#include <iostream>
using namespace std;

// ���� ElemType ����������
typedef int ElemType;

// ����������
struct ListNode {
    ElemType data;
    ListNode *next;
};

// ������������
typedef ListNode *List;

// ����������
int ListLength(List L) {
    int length = 0;
    ListNode *current = L;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}

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
}

// �������в���ָ��Ԫ�ص�λ��
int LocateElem(List L, ElemType e) {
    int index = 0;
    ListNode *current = L;
    while (current != nullptr) {
        index++;
        if (current->data == e) {
            return index;
        }
        current = current->next;
    }
    return 0; // �Ҳ������� 0
}

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

//�����е������Ա�Lb�е�����La�е����ݲ��뵽La��
void unionL(List *La, List Lb){
    int La_len, Lb_len;
    ElemType e;                  //������La��Lb��ͬ������Ԫ��e;
    La_len = ListLength(*La);   //�󳤶�
    Lb_len = ListLength(Lb);
    for (int i = 1; i <= Lb_len; i++)
    {
        GetElem(Lb, i, &e);     /*ȡLb�е�i������Ԫ�ظ���e*/
        if(!LocateElem(*La, e))/*La�в����ں�e��ͬ������Ԫ��*/
            ListInsert(La, ++La_len, e);/*����*/
    }
}

int main(){

    return 0;
}