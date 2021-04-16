#include <bits/stdc++.h>
using namespace std;
// int robRange(vector<int> &nums, int start, int end)
// {
//     int first = nums[start], second = max(nums[start], nums[start + 1]);
//     for (int i = start + 2; i <= end; i++)
//     {
//         int temp = second;
//         second = max(first + nums[i], second);
//         first = temp;
//     }
//     return second;
// }
// int rob(vector<int> &nums)
// {
//     int length = nums.size();
//     if (length == 1)
//     {
//         return nums[0];
//     }
//     else if (length == 2)
//     {
//         return max(nums[0], nums[1]);
//     }
//     return max(robRange(nums, 0, length - 2), robRange(nums, 1, length - 1));
// }

int rob1(vector<int> &nums, int start, int end)
{
    int prevMax = 0;
    int currMax = 0;
    for (int i = start; i < end; i++)
    {
        int temp = currMax;
        cout << nums[i] + prevMax << " " << currMax << endl;
        currMax = max(nums[i] + prevMax, currMax);
        prevMax = temp;
    }
    cout << currMax << endl;
    return currMax;
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];
    int Max1 = rob1(nums, 0, n - 1); //不偷窃最后一个房子
    int Max2 = rob1(nums, 1, n);     //不偷窃第一个房子
    return max(Max1, Max2);
}
int main()
{
    vector<int> nums1 = {1, 2, 3, 1};
    cout << rob(nums1) << endl;
    system("pause");
    return 0;
}