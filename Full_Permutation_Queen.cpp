/*
123 132
213 231
312 321
*/
#include <cstdio>
#include <iostream>
const int maxn = 11;
int n, p[maxn], hashTable[maxn] = {false};
void genP(int index)
{
    if (index == n + 1)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d", p[i]);
        }
        printf("\n");
        return;
    }
    for (int x = 1; x <= n; x++)
    {
        if (hashTable[x] == false)
        {
            p[index] = x;
            hashTable[x] = true;
            genP(index + 1);
            hashTable[x] = false;
        }
    }
}
int count = 0;
void queen(int index)
{
    if (index == n + 1)
    {
        bool flag = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                //行列相差一致则在同一对角线上
                if (abs(i - j) == abs(p[i] - p[j]))
                {
                    flag = false;
                }
            }
        }
        if (flag)
            count++;
        return;
    }
    for (int x = 0; x < n; x++)
    {
        if (hashTable[x] == false)
        {
            p[index] = x;
            hashTable[x] = true;
            queen(index + 1);
            hashTable[x] = false;
        }
    }
}
void queen_plus(int index)
{
    if (index == n + 1)
    {
        count++;
        return;
    }
    for (int x = 0; x <= n; x++)
    {
        if (hashTable[x] == false)
        {
            bool flag = true;
            for (int pre = 0; pre < index; pre++)
            {
                if (abs(index - pre) == abs(x - p[pre]))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                p[index] = x;
                hashTable[x] = true;
                queen(index + 1);
                hashTable[x] = false;
            }
        }
    }
}
int main()
{
    n = 3;
    genP(1);
    system("pause");
    return 0;
}