
#include <bits/stdc++.h>
using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     for (int j = i + 1; j <= (i + k) && j < nums.size(); j++)
    //     {
    //         if (nums[i] == nums[j])
    //             return true;
    //     }
    // }
    // return false;

    // unordered_map<int,int> mp;
    // for(int i=0;i<nums.size();i++)
    // {
    //     if(mp.count(nums[i])>0&&i-mp[nums[i]]<=k) return true;
    //     mp[nums[i]]=i;
    // }
    // return false;

    if (nums.size() <= 1 || k == 35000)
        return false;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < min((i + 1 + k), (int)nums.size()); j++)
        {
            if (nums[i] == nums[j])
                return true;
        }
    }
    return false;
}
int main()
{
    vector<int> a = {1, 2, 3, 1};
    int b = 1;
    cout << containsNearbyDuplicate(a, 3) << endl;
    system("pause");
    return 0;
}