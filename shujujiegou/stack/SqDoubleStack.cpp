#define MAXSIZE 100
typedef int SElemType;/*SElemType类型根据实际情况而定，这里假设为int*/

/*两栈共享空间*/
typedef struct 
{
    SElemType data[MAXSIZE];
    int top1;/*栈1栈顶指针*/
    int top2;/*栈2栈顶指针*/
}SqDoubleStack;

/*插入元素e为新的栈顶元素*/
bool Push(SqDoubleStack *S, SElemType e, int stackNumber){
    if(S -> top1 + 1 == S -> top2)/*栈满，不能再push元素*/
        return false;
    if(stackNumber == 1)        /*栈1有元素入栈*/
        S -> data[++S -> top1] = e;/*若栈1则先top + 1后给数组元素赋值*/
    else if(stackNumber == 2)   /*栈2有元素入栈*/
        S -> data[--S -> top2] = e;/*若栈2则先top - 1后给数组元素赋值*/
    return true;
}

bool Pop(SqDoubleStack *S, SElemType *e, int stackNumber){
    if(stackNumber == 1){
        if(S -> top1 == -1)/*说明栈1已经是空栈，溢出*/
            return false;
        *e = S -> data[S -> top1--];/*将栈1的栈顶元素出栈*/
    }
    else if (stackNumber == 2){
     if(S -> top2 == MAXSIZE)/*说明栈2已经是空栈，溢出*/
            return false;
        *e = S -> data[S -> top2++];/*将栈2的栈顶元素出栈*/
    }   
    return true;
}