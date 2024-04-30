#include <bits/stdc++.h>
using namespace std;

typedef char ElemType;

// 线索储存标志位
// Link(0),表示指向左右的指针
// Thread(1),表示指向前驱后继的线索

typedef enum
{
    Link,
    Thread
} PointerTag; // 枚举

typedef struct BiThrNode
{
    char data;
    struct BiThrNode *lchild, *rchild;
    PointerTag ltag;
    PointerTag rtag;
} BiThrNode, *BiThrTree;

// 全局变量，始终指向刚刚访问过的结点
BiThrTree pre;

// 创建二叉树(前序输入)
void CreateBiThrtree(BiThrTree *T)
{
    char c;
    cin >> c;
    if (' ' == c) /*#表示空树*/
        *T = NULL;
    else
    {
        (*T) = (BiThrNode *)(sizeof(BiThrNode));
        (*T)->data = c; // 生成根结点
        (*T)->ltag = Link;
        (*T)->rtag = Link;

        CreateBiThrtree(&(*T)->lchild); // 构造左子树
        CreateBiThrtree(&(*T)->rchild); // 构造右子树
    }
}

// 中序遍历
void InThreading(BiThrTree T)
{
    if (T)
    {
        InThreading(T->lchild); // 递归左孩子线索化

        if (!T->lchild) // 如果该结点没有左孩子，设置ltag为Thread，并把lchild指向刚刚访问的结点
        {
            T->ltag = Thread; // 前驱线索
            T->lchild = pre;  // 左孩子指针指向前驱
        }
        if (!pre->rchild) // 前驱没有右孩子
        {
            pre->rtag = Thread; // 后继线索
            pre->rchild = T;    // 前驱有孩子指针指向后继(当前结点T)
        }
        pre = T;                // 保持pre指向T的前驱
        InThreading(T->rchild); // 递归右孩子线索化
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

// 你干嘛~
void visit(char c)
{
    cout << c;
}

// 中序遍历二叉树,非递归
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
    cout << "中序遍历输出结果为：";
    InOrderTraverse(p);
    return 0;
}