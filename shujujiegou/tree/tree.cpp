/*树的双亲表示法结点结构定义*/
#define MAX_TREE_SIZE 100
typedef int TElemType; /*定义树节点类型*/
typedef struct PTNode  /*结点结构*/
{
    TElemType data; /*结点数据*/
    int parent;     /*双亲位置（指针）*/
};

typedef struct /*树*/
{
    PTNode node[MAX_TREE_SIZE]; /*结点数组*/
    int r, n;                   /*根的位置和结点数*/
} PTtree;
// 注：根结点的双亲parent = -1
/*********************************************************************************/
/*树的孩子表示法结构定义*/
#define MAX_TREE_SIZE 100
typedef struct CTNode /*孩子结点*/
{
    int child;
    struct CTNode *next; // 指向下一个孩子的指针
} *ChildPtr;
typedef struct /*表头结构*/
{
    TElemType data;      // 存放树中的结点数据
    ChildPtr firstchild; // 指向第一个孩子的指针
} CTBox;

typedef struct /*树结构*/
{
    CTBox nodes[MAX_TREE_SIZE]; /*结点数组*/
    int r, n;                   /*根的位置和结点数*/
} CTree;
/*********************************************************************************/
/*树的孩子兄弟表示法结构定义*/
typedef struct CSNode
{
    TElemType data;
    struct CSNode *firstchild, *rightsilb;
} CSNode, *CSTree;
