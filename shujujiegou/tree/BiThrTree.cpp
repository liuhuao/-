#include <bits/stdc++.h>
using namespace std;

typedef char ElemType;

// ���������־λ
// Link(0),��ʾָ�����ҵ�ָ��
// Thread(1),��ʾָ��ǰ����̵�����

typedef enum
{
    Link,
    Thread
} PointerTag; // ö��

typedef struct BiThrNode
{
    char data;
    struct BiThrNode *lchild, *rchild;
    PointerTag ltag;
    PointerTag rtag;
} BiThrNode, *BiThrTree;

// ȫ�ֱ�����ʼ��ָ��ոշ��ʹ��Ľ��
BiThrTree pre;

// ����������(ǰ������)
void CreateBiThrtree(BiThrTree *T)
{
    char c;
    cin >> c;
    if (' ' == c) /*#��ʾ����*/
        *T = NULL;
    else
    {
        (*T) = (BiThrNode *)(sizeof(BiThrNode));
        (*T)->data = c; // ���ɸ����
        (*T)->ltag = Link;
        (*T)->rtag = Link;

        CreateBiThrtree(&(*T)->lchild); // ����������
        CreateBiThrtree(&(*T)->rchild); // ����������
    }
}

// �������
void InThreading(BiThrTree T)
{
    if (T)
    {
        InThreading(T->lchild); // �ݹ�����������

        if (!T->lchild) // ����ý��û�����ӣ�����ltagΪThread������lchildָ��ոշ��ʵĽ��
        {
            T->ltag = Thread; // ǰ������
            T->lchild = pre;  // ����ָ��ָ��ǰ��
        }
        if (!pre->rchild) // ǰ��û���Һ���
        {
            pre->rtag = Thread; // �������
            pre->rchild = T;    // ǰ���к���ָ��ָ����(��ǰ���T)
        }
        pre = T;                // ����preָ��T��ǰ��
        InThreading(T->rchild); // �ݹ��Һ���������
    }
}

void InorderThreading(BiThrTree *p, BiThrTree T)
{
    *p = (BiThrTree)(sizeof(BiThrNode));
    (*p)->ltag = Link;
    (*p)->rtag = Thread;
    (*p)->rchild = *p;
    if (!T)
    {
        (*p)->rchild = *p;
    }
    else
    {
        (*p)->lchild = *p;
        pre = *p;
        InThreading(T);
        pre->rchild = *p;
        pre->rtag = Thread;
        (*p)->rchild = pre;
    }
}

// �����~
void visit(char c)
{
    cout << c;
}

// �������������,�ǵݹ�
void InOrderTraverse(BiThrTree T)
{
    BiThrTree p;
    p = T->lchild;

    while (p != T)
    {
        while (p->ltag == Link)
        {
            p = p->lchild;
        }
        visit(p->data);

        while (p->rtag == Thread && p->rchild != T)
        {
            p = p->rchild;
            visit(p->data);
        }
        p = p->rchild;
    }
}

int main()
{
    BiThrTree p, T = NULL;
    CreateBiThrtree(&T);
    InorderThreading(&p, T);
    cout << "�������������Ϊ��";
    InOrderTraverse(p);
    return 0;
}