/*TΪ�ǿ��ַ������������е�pos���ַ�֮�������T��ȵ��ִ�*/
/*�򷵻ص�һ���������Ӵ���s�е�λ�ã����򷵻�0*/
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
            string sub = S.substr(i, m); // ȡ�����ĵ�i��λ��
            //                      ���ѳ�����T����Ӵ���sub
            if (sub == T) // ������������
                i++;
            else // ���
                return i;
        }
    }
}

