#include <bits/stdc++.h>
using namespace std;
int removeElement(vector<int> &nums, int val)
{
    int pre = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
            nums[pre++] = nums[i];
    }
    return pre;
}