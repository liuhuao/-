#include <iostream>
using namespace std;

typedef char ElemType;

typedef struct BiTNode
{
    char data; 
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 创建二叉树
void CreateBiTree(BiTree &T)
{
    char c;
    cin >> c;
    if ('#' == c) /*#表示空树*/
        T = NULL;
    else
    {
        T = new BiTNode;
        T->data = c;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

// 访问二叉树具体操作
void visit(char c, int level)
{
    cout << c << "位于" << level << "层 " << endl;
}

// 遍历二叉树(前序)
/*二叉树的前序遍历递归算法*/
void PreOderTraverse(BiTree T, int level)
{
    if (T == NULL)
        return;
    else
    {
        visit(T->data, level);
        PreOderTraverse(T->lchild, level + 1); /*再先序遍历左子树*/
        PreOderTraverse(T->rchild, level + 1); /*最后先序遍历右子树*/
    }
}

int main()
{
    int level = 1;
    BiTree T = NULL;

    cout << "请输入二叉树的结点数据（空结点用#表示）：";
    CreateBiTree(T);
    cout << "二叉树创建结果：" << endl;
    PreOderTraverse(T, level);

    return 0;
}
