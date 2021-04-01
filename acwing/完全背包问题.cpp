#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int n, maxV, w[maxn], v[maxn], dp[maxn];
int main()
{
    scanf("%d%d", &n, &maxV);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &v[i], &w[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = v[i] ; j <=maxV ;j++)
        {
            dp[j] = max(dp[j], dp[j-v[i]] + w[i]);
        }
    }
    printf("%d\n", dp[maxV]);
    return 0;
}