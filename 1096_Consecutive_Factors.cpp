#include <bits/stdc++.h>
using namespace std;
int main()
{
    long n, tmp;
    cin >> n;
    int max = sqrt(n);
    int len = 0, pre = 0;
    for (int i = 2; i <= max; i++)
    {
        int j;
        tmp = 1;
        for (j = i; j <= max; j++)
        {
            tmp *= j;
            if (n % tmp != 0) //非因子
                break;
        }
        if (j - i > len)
        {
            len = j - i;
            pre = i;
        }
    }
    if (pre == 0)
        cout << 1 << endl
             << n << endl;
    else
    {
        cout << len << endl
             << pre;
        for (int i = 1; i < len; i++)
            cout << "*" << ++pre;
    }
    return 0;
}