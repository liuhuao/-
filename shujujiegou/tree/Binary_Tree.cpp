#include<bits/stdc++.h>
using namespace std;
typedef int TElemType; /*定义树节点类型*/

/*二叉树的二叉链表结点结构定义*/
typedef struct BiTNode /*结点结构*/
{
    TElemType data;                  /*结点数据*/
    struct BiTNode *lchild, *rchild; /*左右孩子指针*/
} BiNode, *BiTree;

/************************************************************************/

/*二叉树的前序遍历递归算法*/
void PreOderTraverse(BiTree T)
{
    if (T == NULL)
        return ;
    cout << T->data;            /*显示结点数据*/
    PreOderTraverse(T->lchild); /*再先序遍历左子树*/
    PreOderTraverse(T->rchild); /*最后先序遍历右子树*/
}

/************************************************************************/

/*二叉树的中序遍历递归算法*/
void InOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    InOrderTraverse(T->lchild); /*中序遍历左子树*/
    cout << T->data;            /*显示结点数据*/
    InOrderTraverse(T->rchild); /*最后中序遍历右子树*/
}

/************************************************************************/

/*二叉树的后序遍历递归算法*/
void PostOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    PostOrderTraverse(T->lchild); /*先后序遍历左子树*/
    PostOrderTraverse(T->lchild); /*在后序遍历右子树*/
    cout << T->data;              /*显示结点数据*/
}

/************************************************************************/

