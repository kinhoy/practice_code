// #include <iostream>
// #include <algorithm>
// using namespace std;
// const int maxn = 1010;
// int n, maxV, w[maxn], v[maxn], dp[maxn][maxn];
// int main()
// {
//     scanf("%d%d", &n, &maxV);
//     for (int i = 1; i <= n; i++)
//     {
//         scanf("%d %d", &v[i], &w[i]);
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 0; j <= maxV; j++)
//         {
//             dp[i][j] = dp[i - 1][j];
//             if (j >= v[i])
//                 dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
//         }
//     }
//     for (int i = 0; i <= n; i++)
//     {
//         for (int j = 0; j <= maxV; j++)
//         {
//             cout << dp[i][j] << ' ';
//         }
//         cout << endl;
//     }
//     printf("%d\n", dp[n][maxV]);
//     return 0;
// }
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
        for (int j = maxV ; j >=v[i] ;j--)
        {
            dp[j] = max(dp[j], dp[j-v[i]] + w[i]);
        }
    }
    printf("%d\n", dp[maxV]);
    return 0;
}
