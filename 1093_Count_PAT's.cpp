#include <bits/stdc++.h>
using namespace std;
#define max 1000000007
int main()
{
    int p = 0, a = 0;
    long long cnt = 0;
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'P')
            p++;
        else if (str[i] == 'A')
            a += p;
        else if (str[i] == 'T')
            cnt += a;
    }
    cnt %= max;
    cout << cnt;
    system("pause");
    return 0;
}