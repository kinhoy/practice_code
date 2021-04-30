#include <bits/stdc++.h>
using namespace std;
int singleNumber(vector<int> &nums)
{
    int ones = 0, twos = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ones = ones ^ nums[i] & ~twos;
        twos = twos ^ nums[i] & ~ones;
    }
    return ones;
}
int singleNumber2(vector<int> &nums)
{
    unordered_map<int, int> freq;
    for (int num : nums)
    {
        ++freq[num];
    }
    int ans = 0;
    for (auto [num, occ] : freq)
    {
        if (occ == 1)
        {
            ans = num;
            break;
        }
    }
    return ans;
}