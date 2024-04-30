#define MAXSIZE 100
typedef int SElemType;/*SElemType类型根据实际情况而定，这里假设为int*/
typedef struct 
{
    SElemType data[MAXSIZE];
    int top;            /*用于栈顶指针*/
}SqStack;

/*插入元素e为新的栈顶元素*/
bool Push(SqStack *s, SElemType e){
    if(s -> top == MAXSIZE - 1) /*栈满*/
        return false;
    s -> top++;                 /*栈顶指针加一*/
    s -> data[s -> top] = e;    /*将新插入元素赋值给栈顶空间*/
    return true;
}

/*若栈不为空，则删除S的栈顶元素，用e返回其值，并返回true;否则返回false*/
bool pop(SqStack *S, SElemType *e){
    if(S -> top == 1)
        return false;
    *e = S -> data[S -> top];   /*将要删除的栈顶元素赋值给e*/
    S -> top--;                 /*栈顶指针减一*/
    return true;
}