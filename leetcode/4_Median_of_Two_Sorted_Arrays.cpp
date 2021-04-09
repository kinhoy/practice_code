
#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int findKth(vector<int> nums1, int pre1, vector<int> nums2, int pre2, int k)
{
    if (pre1 >= nums1.size())
        return nums2[pre2 + k - 1]; //nums1为空数组
    if (pre2 >= nums2.size())
        return nums1[pre1 + k - 1]; //nums2为空数组
    if (k == 1)
        return nums1[pre1] > nums2[pre2] ? nums2[pre2] : nums1[pre1];
    int m1 = (pre1 + k / 2 - 1 < nums1.size()) ? nums1[pre1 + k / 2 - 1] : INT_MAX;
    int m2 = (pre2 + k / 2 - 1 < nums2.size()) ? nums2[pre2 + k / 2 - 1] : INT_MAX;
    if (m1 < m2)
        return findKth(nums1, pre1 + k / 2, nums2, pre2, k - k / 2);
    else
        return findKth(nums1, pre1, nums2, pre2 + k / 2, k - k / 2);
}
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    int x = (m + n + 1) / 2, y = (m + n + 2) / 2;
    if (x == y)
        return findKth(nums1, 0, nums2, 0, x);
    return (findKth(nums1, 0, nums2, 0, x) + findKth(nums1, 0, nums2, 0, y)) / 2.0;
}
int main()
{
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    system("pause");
    return 0;
}