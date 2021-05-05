#include <bits/stdc++.h>
using namespace std;
int deleteAndEarn(vector<int> &nums)
{
    // if(nums.size() < 1) return 0;
    // int maxn = 0;
    // for(int it : nums)
    //     maxn = max(maxn, it);
    // vector<int> cnt(maxn+1), dp(maxn+1);
    // for(int it : nums)
    //     cnt[it]++;
    // dp[1] = cnt[1];
    // for(int i = 2; i <= maxn; i++)
    //     dp[i] = max(dp[i-1], dp[i-2] + cnt[i] * i);
    // return dp[maxn];

    int bet[10001] = {0};
    for (int n = 0; n < nums.size(); n++)
        bet[nums[n]] += nums[n];
    for (int n = 2; n <= 10000; n++)
    {
        if (bet[n] + bet[n - 2] > bet[n - 1])
            bet[n] += bet[n - 2];
        else
            bet[n] = bet[n - 1];
    }
    return bet[10000];
}