#include <iostream>
using namespace std;

typedef char ElemType;

typedef struct BiTNode
{
    char data; 
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// ����������
void CreateBiTree(BiTree &T)
{
    char c;
    cin >> c;
    if ('#' == c) /*#��ʾ����*/
        T = NULL;
    else
    {
        T = new BiTNode;
        T->data = c;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

// ���ʶ������������
void visit(char c, int level)
{
    cout << c << "λ��" << level << "�� " << endl;
}

// ����������(ǰ��)
/*��������ǰ������ݹ��㷨*/
void PreOderTraverse(BiTree T, int level)
{
    if (T == NULL)
        return;
    else
    {
        visit(T->data, level);
        PreOderTraverse(T->lchild, level + 1); /*���������������*/
        PreOderTraverse(T->rchild, level + 1); /*����������������*/
    }
}

int main()
{
    int level = 1;
    BiTree T = NULL;

    cout << "������������Ľ�����ݣ��ս����#��ʾ����";
    CreateBiTree(T);
    cout << "���������������" << endl;
    PreOderTraverse(T, level);

    return 0;
}
