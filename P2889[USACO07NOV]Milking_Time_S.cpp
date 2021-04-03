#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1010;
struct time
{
    int st, ed, p, next;
} a[N];
int dp[N], head[N];
int main()
{
    int n, m, r, i, j, k;
    scanf("%d%d%d", &n, &m, &r);
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &a[i].st, &a[i].ed, &a[i].p);
        a[i].next = head[a[i].ed];
        head[a[i].ed] = i; //前向星
    }
    memset(dp, 0, sizeof(dp));
    for (j = 1; j <= n; j++)
    {
        dp[j] = dp[j - 1];
        for (i = head[j]; i; i = a[i].next)
            dp[j] = max(dp[j], dp[max(0, a[i].st - r)] + a[i].p); //第一次挤奶不需要等待r
    }
    cout << dp[n] << endl;
    return 0;
}