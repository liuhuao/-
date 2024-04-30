#define MAXSIZE 100
typedef int SElemType;/*SElemType���͸���ʵ������������������Ϊint*/
typedef struct 
{
    SElemType data[MAXSIZE];
    int top;            /*����ջ��ָ��*/
}SqStack;

/*����Ԫ��eΪ�µ�ջ��Ԫ��*/
bool Push(SqStack *s, SElemType e){
    if(s -> top == MAXSIZE - 1) /*ջ��*/
        return false;
    s -> top++;                 /*ջ��ָ���һ*/
    s -> data[s -> top] = e;    /*���²���Ԫ�ظ�ֵ��ջ���ռ�*/
    return true;
}

/*��ջ��Ϊ�գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������true;���򷵻�false*/
bool pop(SqStack *S, SElemType *e){
    if(S -> top == 1)
        return false;
    *e = S -> data[S -> top];   /*��Ҫɾ����ջ��Ԫ�ظ�ֵ��e*/
    S -> top--;                 /*ջ��ָ���һ*/
    return true;
}