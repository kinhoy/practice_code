
#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int search(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1;
    int k = nums[0];
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (nums[mid] == target)
            return mid;
        //if ((target >= k && nums[mid] > target) || (target < nums[mid] && nums[mid] < k))
        if ((k > target) ^ (k > nums[mid]) ^ (target > nums[mid]))
            l = mid + 1;
        else
            r = mid;
        cout << "L:" << l << " R:" << r << endl;
    }
    return l == r && nums[l] == target ? l : -1;
}
int main()
{
    vector<int> a = {1,3,5};
    int b = 1;
    cout << search(a, b) << endl;
    system("pause");
    return 0;
}