/*˫������Ĵ���ṹ*/
typedef int ElemType;  
typedef struct DulNode
{
    ElemType data;
    struct DulNode *prior; /*ֱ��ǰ��ָ��*/
    struct DulNode *next; /*ֱ�Ӻ���ָ��*/
};
