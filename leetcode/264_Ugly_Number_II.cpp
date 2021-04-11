#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int nthUglyNumber(int n)
{
    int dp[n];
    dp[0] = 1;
    int p_2, p_3, p_5;
    p_2 = p_3 = p_5 = 0;
    for (int i = 1; i < n; ++i)
    {
        dp[i] = min(min(2 * dp[p_2], 3 * dp[p_3]), 5 * dp[p_5]);
        if (dp[i] == 2 * dp[p_2])
            ++p_2;
        if (dp[i] == 3 * dp[p_3])
            ++p_3;
        if (dp[i] == 5 * dp[p_5])
            ++p_5;
    }
    return dp[n - 1];
}
int main()
{
    cout << nthUglyNumber(10) << endl;
    system("pause");
    return 0;
}