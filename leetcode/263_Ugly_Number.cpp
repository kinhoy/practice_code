#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
bool isUgly(int n)
{
    if (n <= 0)
    {
        return false;
    }
    int a[] = {2, 3, 5};
    for (int i = 0; i < 3; i++)
    {
        while (n % a[i] == 0)
        {
            n /= a[i];
        }
    }
    return n == 1;
}
int main()
{
    cout << isUgly(14) << endl;
    system("pause");
    return 0;
}