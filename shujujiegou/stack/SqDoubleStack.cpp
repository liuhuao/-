#define MAXSIZE 100
typedef int SElemType;/*SElemType���͸���ʵ������������������Ϊint*/

/*��ջ����ռ�*/
typedef struct 
{
    SElemType data[MAXSIZE];
    int top1;/*ջ1ջ��ָ��*/
    int top2;/*ջ2ջ��ָ��*/
}SqDoubleStack;

/*����Ԫ��eΪ�µ�ջ��Ԫ��*/
bool Push(SqDoubleStack *S, SElemType e, int stackNumber){
    if(S -> top1 + 1 == S -> top2)/*ջ����������pushԪ��*/
        return false;
    if(stackNumber == 1)        /*ջ1��Ԫ����ջ*/
        S -> data[++S -> top1] = e;/*��ջ1����top + 1�������Ԫ�ظ�ֵ*/
    else if(stackNumber == 2)   /*ջ2��Ԫ����ջ*/
        S -> data[--S -> top2] = e;/*��ջ2����top - 1�������Ԫ�ظ�ֵ*/
    return true;
}

bool Pop(SqDoubleStack *S, SElemType *e, int stackNumber){
    if(stackNumber == 1){
        if(S -> top1 == -1)/*˵��ջ1�Ѿ��ǿ�ջ�����*/
            return false;
        *e = S -> data[S -> top1--];/*��ջ1��ջ��Ԫ�س�ջ*/
    }
    else if (stackNumber == 2){
     if(S -> top2 == MAXSIZE)/*˵��ջ2�Ѿ��ǿ�ջ�����*/
            return false;
        *e = S -> data[S -> top2++];/*��ջ2��ջ��Ԫ�س�ջ*/
    }   
    return true;
}