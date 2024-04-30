typedef int QElemType;/*QElemType类型根据情况而定，这里使用int*/
typedef struct QNpde/*结点结构*/
{
    QElemType data;
    struct QNode *next;    
}QNode,*QueuePtr;

typedef struct LinkQueue /*队列的链表结构*/
{
    QueuePtr front,rear;/*队头队尾指针*/
};

/*插入元素e为Q的新的队尾元素*/
bool EnQueue(LinkQueue *Q, QElemType e){
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    if(!s)//储存分配失败
        exit(OVERFLOW);
    s -> data = e;
    s -> next = NULL;
    Q ->rear->next = s;/*将拥有元素e新结点s赋值给原队尾结点的后继*/
    Q -> rear = s;
    return true;/*把当前的s设置为队尾结点，rear指向s*/
}

/*若队列不空，删除Q的队头元素，用e返回其值*/
bool DeQueue(LinkQueue *Q,QElemType *e){
    QueuePtr p;
    if(Q -> front == Q -> rear)
        return flase;
    p = Q -> front -> next; /*将欲删除的队头结点暂存给p*/
    *e = p -> data;/*将欲删除的队头结点的值赋值给e*/
    Q -> front -> next = p -> next;/*将队头结点后继p->next赋值给头结点后继*/
    if(Q -> rear == p)  //若队头是队尾，则删除后将rear指向头结点
        Q ->rear = Q -> front;
    free(p);
    return true;
}