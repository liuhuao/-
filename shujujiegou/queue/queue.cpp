typedef int QElemType; /*QElemType���͸�������������������Ϊint */
/*ѭ�����е�˳��洢�ṹ*/
#define MAXSIZE 20            /*�洢�ռ��ʼ������*/

typedef struct sqQueue
{
    QElemType data[MAXSIZE];
    int front;        /*ͷָ�룬��ͷ*/
    int rear; /*βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��*/
};

// ��ʼ��һ���ն���
bool InitQueue(sqQueue *Q)
{
    Q -> front = 0;
    Q -> rear = 0;
    return true;
}

//����Q��Ԫ�ظ���=> ����г���
int QueueLenth(sqQueue Q){
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

//������δ���������Ԫ��eΪQ�µĶ�βԪ��
bool EnQueue (sqQueue *Q, QElemType e){
    if((Q -> rear + 1) % MAXSIZE == Q -> front)/*��������*/
        return false;
    Q -> data[Q -> rear] = e;           /*��Ԫ��e��ֵ����β*/
    Q -> rear = (Q -> rear + 1) % MAXSIZE;/*rearָ�������һ��λ��*/
                                          /*���������ת������ͷ��*/
    return true;
}

//�����в��գ���ɾ��Q�еĶ�ͷԪ�أ���e������ֵ
bool DeQueue (sqQueue *Q, QElemType *e){
    if(Q -> front = Q-> rear)/*���п���*/
        return false;
    *e = Q -> data[Q -> front];           /*����ͷԪ�ظ�ֵ��e*/
    Q -> front = (Q -> front + 1) % MAXSIZE;/*frontָ�������һ��λ��*/
                                          /*���������ת������ͷ��*/
    return true;
}