#include <bits/stdc++.h>
using namespace std;
/*ͨ�����㷵���ִ�T��next����*/
void get_next(string T, int *next)
{
    int i, j;
    i = 1;
    j = 0;
    next[1] = 0;
    while (i < T[0])
    {                               /*T[0]��ʾ����*/
        if (j == 0 || T[i] == T[j]) /*T[i] ��ʾ��׺�ĵ����ַ�*/
                                    /*T[j] ��ʾǰ׺�ĵ����ַ�*/
        {
            i++;
            j++;
            if(T[i] != T[j])  /*����ǰ���ַ���ǰ׺�ַ���ͬ*/
                next[i] = j; /*��ǰ��jΪnext��iλ�õ�ֵ*/
            else
                next[i] = next[j]; /*�����ͬ*/
        }
        else
        {
            j = next[j];    /*���ַ�����ͬ����jֵ����*/
        }
    }
}
