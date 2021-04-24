#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int combinationSum4(vector<int> &nums, int target)
{
    if (target == 0)
        return 1;
    if (mp.count(target))
        return mp[target];
    int res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (target >= nums[i])
            res += combinationSum4(nums, target - nums[i]);
    }
    mp[target] = res;
    return res;
}
int main()
{
    vector<int> a = {1, 2, 3};
    int target = 4;
    cout << combinationSum4(a, target) << endl;
    system("pause");
    return 0;
}
// int combinationSum4(vector<int> &nums, int target)
// {
//     vector<int> dp(target + 1);
//     dp[0] = 1;
//     for (int i = 1; i <= target; i++)
//     {
//         for (int &num : nums)
//         {
//             if (num <= i && dp[i - num] < INT_MAX - dp[i])
//             {
//                 dp[i] += dp[i - num];
//             }
//         }
//     }
//     return dp[target];
// }
