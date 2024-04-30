#include<bits/stdc++.h>
using namespace std;
typedef int TElemType; /*�������ڵ�����*/

/*�������Ķ���������ṹ����*/
typedef struct BiTNode /*���ṹ*/
{
    TElemType data;                  /*�������*/
    struct BiTNode *lchild, *rchild; /*���Һ���ָ��*/
} BiNode, *BiTree;

/************************************************************************/

/*��������ǰ������ݹ��㷨*/
void PreOderTraverse(BiTree T)
{
    if (T == NULL)
        return ;
    cout << T->data;            /*��ʾ�������*/
    PreOderTraverse(T->lchild); /*���������������*/
    PreOderTraverse(T->rchild); /*����������������*/
}

/************************************************************************/

/*����������������ݹ��㷨*/
void InOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    InOrderTraverse(T->lchild); /*�������������*/
    cout << T->data;            /*��ʾ�������*/
    InOrderTraverse(T->rchild); /*����������������*/
}

/************************************************************************/

/*�������ĺ�������ݹ��㷨*/
void PostOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    PostOrderTraverse(T->lchild); /*�Ⱥ������������*/
    PostOrderTraverse(T->lchild); /*�ں������������*/
    cout << T->data;              /*��ʾ�������*/
}

/************************************************************************/

