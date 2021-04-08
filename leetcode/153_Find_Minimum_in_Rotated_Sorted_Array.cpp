
#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int findMin(vector<int> &nums)
{
    int l = 0, r = nums.size() - 1;
    int k = nums[0];
    if (k <= nums[r] || r == 0)
        return k;
    if (k > nums[r] && r == 1)
        return nums[r];
    while (l < r)
    {
        int mid = (l + r) / 2;
        if ((mid > 0 && nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) || (mid < nums.size() - 2 && nums[mid] > nums[mid + 1] && nums[mid + 2] > nums[mid + 1]))
            return nums[mid + 1];
        if (k < nums[mid])
            l = mid + 1;
        else
            r = mid;
    }
    return nums[l];
}
int officialfindMin(vector<int> &nums)
{
    int low = 0;
    int high = nums.size() - 1;
    while (low < high)
    {
        int pivot = low + (high - low) / 2;
        if (nums[pivot] < nums[high])
        {
            high = pivot;
        }
        else
        {
            low = pivot + 1;
        }
    }
    return nums[low];
}
int main()
{
    vector<int> a = {2, 1};
    cout << findMin(a) << endl;
    system("pause");
    return 0;
}