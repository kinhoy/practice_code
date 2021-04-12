#include <bits/stdc++.h>
using namespace std;
string largestNumber(vector<int> &nums)
{
    string s;
    sort(nums.begin(), nums.end(), [](int x, int y) {
        string a = to_string(x), b = to_string(y);
        return a + b > b + a;
    });
    if (nums[0] == 0)
        return "0";
    for (int i = 0; i < nums.size(); i++)
    {
        s += to_string(nums[i]);
    }
    return s;
}
int main()
{
    vector<int> nums = {0};
    cout << largestNumber(nums) << endl;
    system("pause");
    return 0;
}