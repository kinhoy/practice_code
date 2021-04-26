#include <bits/stdc++.h>
#include <algorithm> // std::max_element
#include <numeric>   // std::accumulate
using namespace std;
int shipWithinDays(vector<int> &weights, int D)
{
    int n = weights.size();
    int l = *max_element(weights.begin(), weights.end());
    int r = accumulate(weights.begin(), weights.end(), 0);
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (caculate(weights, mid) <= D)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}
int caculate(vector<int> &weights, int cap)
{
    int day = 1; // 注意：初始值应该为 1，因为哪怕船装不满 day 也应该加 1
    int sum = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        sum += weights[i];
        if (sum > cap)
        {
            day++;
            sum = weights[i];
        }
    }
    return day;
}