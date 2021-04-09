
#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int findMin(vector<int> &nums)
{
    int low = 0;
    int high = nums.size() - 1;
    while (low < high)
    {
        if (nums[low] == nums[high])
        {
            high--;
            continue;
        }
        int pivot = low + (high - low) / 2;
        if (nums[pivot] <= nums[high])
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
    vector<int> a = {-9, -9, -9, -10, -9 };
    cout << findMin(a) << endl;
    system("pause");
    return 0;
}