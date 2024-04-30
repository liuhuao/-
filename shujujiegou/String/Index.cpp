/*T为非空字符串。若主串中第pos个字符之后存在与T相等的字串*/
/*则返回第一个这样的子串在s中的位置，否则返回0*/
#include <bits/stdc++.h>
using namespace std;

int Index(string S, string T, int pos)
{
    int n, m, i;
    string sub;
    if (pos)
    {
        n = S.length();
        m = T.length();
        i = pos;
        while (i <= n - m + 1)
        {
            string sub = S.substr(i, m); // 取主串的第i个位置
            //                      并把长度与T相等子串给sub
            if (sub == T) // 如果两串不相等
                i++;
            else // 相等
                return i;
        }
    }
}

