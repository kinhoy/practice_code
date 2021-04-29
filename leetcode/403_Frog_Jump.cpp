#include <bits/stdc++.h>
using namespace std;
bool canCross(vector<int> &stones)
{
    bool f[2021][2021];
    memset(f, false, sizeof f);
    int n = stones.size();
    if (stones[1] != 1)
        return false;
    f[1][1] = true;
    for (int i = 2; i < n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            int k = stones[i] - stones[j];
            if (k <= j + 1)
                f[i][k] = f[j][k - 1] || f[j][k] || f[j][k + 1];
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (f[n - 1][i])
            return true;
    }
    return false;
}