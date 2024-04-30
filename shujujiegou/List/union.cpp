#include <iostream>
using namespace std;

// 假设 ElemType 是整数类型
typedef int ElemType;

// 定义链表结点
struct ListNode {
    ElemType data;
    ListNode *next;
};

// 定义链表类型
typedef ListNode *List;

// 计算链表长度
int ListLength(List L) {
    int length = 0;
    ListNode *current = L;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}

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
}

// 在链表中查找指定元素的位置
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
    return 0; // 找不到返回 0
}

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

//将所有的在线性表Lb中但不在La中的数据插入到La中
void unionL(List *La, List Lb){
    int La_len, Lb_len;
    ElemType e;                  //声明与La和Lb相同的数据元素e;
    La_len = ListLength(*La);   //求长度
    Lb_len = ListLength(Lb);
    for (int i = 1; i <= Lb_len; i++)
    {
        GetElem(Lb, i, &e);     /*取Lb中第i个数据元素赋给e*/
        if(!LocateElem(*La, e))/*La中不存在和e相同的数据元素*/
            ListInsert(La, ++La_len, e);/*插入*/
    }
}

int main(){

    return 0;
}