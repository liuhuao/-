#include <bits/stdc++.h>
using namespace std;
/*通过计算返回字串T的next数组*/
void get_next(string T, int *next)
{
    int i, j;
    i = 1;
    j = 0;
    next[1] = 0;
    while (i < T[0])
    {                               /*T[0]表示长度*/
        if (j == 0 || T[i] == T[j]) /*T[i] 表示后缀的单个字符*/
                                    /*T[j] 表示前缀的单个字符*/
        {
            i++;
            j++;
            if(T[i] != T[j])  /*若当前的字符与前缀字符不同*/
                next[i] = j; /*则当前的j为next在i位置的值*/
            else
                next[i] = next[j]; /*如果相同*/
        }
        else
        {
            j = next[j];    /*若字符不相同，则j值回溯*/
        }
    }
}
