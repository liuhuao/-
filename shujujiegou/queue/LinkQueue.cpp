typedef int QElemType;/*QElemType���͸����������������ʹ��int*/
typedef struct QNpde/*���ṹ*/
{
    QElemType data;
    struct QNode *next;    
}QNode,*QueuePtr;

typedef struct LinkQueue /*���е�����ṹ*/
{
    QueuePtr front,rear;/*��ͷ��βָ��*/
};

/*����Ԫ��eΪQ���µĶ�βԪ��*/
bool EnQueue(LinkQueue *Q, QElemType e){
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    if(!s)//�������ʧ��
        exit(OVERFLOW);
    s -> data = e;
    s -> next = NULL;
    Q ->rear->next = s;/*��ӵ��Ԫ��e�½��s��ֵ��ԭ��β���ĺ��*/
    Q -> rear = s;
    return true;/*�ѵ�ǰ��s����Ϊ��β��㣬rearָ��s*/
}

/*�����в��գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ*/
bool DeQueue(LinkQueue *Q,QElemType *e){
    QueuePtr p;
    if(Q -> front == Q -> rear)
        return flase;
    p = Q -> front -> next; /*����ɾ���Ķ�ͷ����ݴ��p*/
    *e = p -> data;/*����ɾ���Ķ�ͷ����ֵ��ֵ��e*/
    Q -> front -> next = p -> next;/*����ͷ�����p->next��ֵ��ͷ�����*/
    if(Q -> rear == p)  //����ͷ�Ƕ�β����ɾ����rearָ��ͷ���
        Q ->rear = Q -> front;
    free(p);
    return true;
}