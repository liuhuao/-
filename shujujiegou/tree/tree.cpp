/*����˫�ױ�ʾ�����ṹ����*/
#define MAX_TREE_SIZE 100
typedef int TElemType; /*�������ڵ�����*/
typedef struct PTNode  /*���ṹ*/
{
    TElemType data; /*�������*/
    int parent;     /*˫��λ�ã�ָ�룩*/
};

typedef struct /*��*/
{
    PTNode node[MAX_TREE_SIZE]; /*�������*/
    int r, n;                   /*����λ�úͽ����*/
} PTtree;
// ע��������˫��parent = -1
/*********************************************************************************/
/*���ĺ��ӱ�ʾ���ṹ����*/
#define MAX_TREE_SIZE 100
typedef struct CTNode /*���ӽ��*/
{
    int child;
    struct CTNode *next; // ָ����һ�����ӵ�ָ��
} *ChildPtr;
typedef struct /*��ͷ�ṹ*/
{
    TElemType data;      // ������еĽ������
    ChildPtr firstchild; // ָ���һ�����ӵ�ָ��
} CTBox;

typedef struct /*���ṹ*/
{
    CTBox nodes[MAX_TREE_SIZE]; /*�������*/
    int r, n;                   /*����λ�úͽ����*/
} CTree;
/*********************************************************************************/
/*���ĺ����ֵܱ�ʾ���ṹ����*/
typedef struct CSNode
{
    TElemType data;
    struct CSNode *firstchild, *rightsilb;
} CSNode, *CSTree;
