typedef int QElemType; /*QElemType类型根据情况而定，这里假设为int */
/*循环队列的顺序存储结构*/
#define MAXSIZE 20            /*存储空间初始分配量*/

typedef struct sqQueue
{
    QElemType data[MAXSIZE];
    int front;        /*头指针，队头*/
    int rear; /*尾指针，若队列不空，指向队列尾元素的下一个位置*/
};

// 初始化一个空队列
bool InitQueue(sqQueue *Q)
{
    Q -> front = 0;
    Q -> rear = 0;
    return true;
}

//返回Q的元素个数=> 求队列长度
int QueueLenth(sqQueue Q){
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

//若队列未满，则插入元素e为Q新的队尾元素
bool EnQueue (sqQueue *Q, QElemType e){
    if((Q -> rear + 1) % MAXSIZE == Q -> front)/*队列满了*/
        return false;
    Q -> data[Q -> rear] = e;           /*将元素e赋值给队尾*/
    Q -> rear = (Q -> rear + 1) % MAXSIZE;/*rear指针向后移一个位置*/
                                          /*若到最后则转到数组头部*/
    return true;
}

//若队列不空，则删除Q中的队头元素，用e返回其值
bool DeQueue (sqQueue *Q, QElemType *e){
    if(Q -> front = Q-> rear)/*队列空了*/
        return false;
    *e = Q -> data[Q -> front];           /*将队头元素赋值给e*/
    Q -> front = (Q -> front + 1) % MAXSIZE;/*front指针向后移一个位置*/
                                          /*若到最后则转到数组头部*/
    return true;
}