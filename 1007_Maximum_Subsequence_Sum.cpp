#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int k;
    scanf("%d", &k);
    vector<int> nums(k);
    int temp = 0, sum = -1, l = 0, tempL = 0, r = k - 1;
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &nums[i]);
        temp += nums[i];
        if (temp < 0)
        {
            temp = 0;
            tempL = i + 1;
        }
        else if (temp > sum)
        {
            sum = temp;
            r = i;
            l = tempL;
        }
    }
    if (sum < 0)
        sum = 0;
    printf("%d %d %d", sum, nums[l], nums[r]);
    return 0;
}

// int k;
// int nums[N];
// scanf("%d", &k);
// for (int i = 0; i < k; i++)
// {
//     scanf("%d", &nums[i]);
// }
// for (int i = 0; i < k; i++)
// {
//     printf("%d", nums[i]);
// }