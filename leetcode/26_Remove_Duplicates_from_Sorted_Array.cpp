#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int> &nums)
{
    int pre = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[pre] != nums[i])
        {
            pre++;
            int t = nums[pre];
            nums[pre] = nums[i];
            nums[i] = t;
        }
    }
    return nums.size() == 0 ? 0 : pre + 1;
}