//升次方 FFT乘法+快速幂+二分
#include <bits/stdc++.h>
typedef long long LL;
#define maxn 10000000007
using namespace std;
LL f(LL x, LL i)
{
    LL res = 1;
    while (i--)
    {
        res *= x;
    }
    return res;
}
//快速幂
LL binaryPow(LL a, LL b, LL m)
{
    LL ans = 1;
    while (b > 0)
    {
        if (b & 1) //若b的二进制末尾为1
        {
            ans = ans * a % m; //ans累积上a
        }
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}
int main()
{
    LL m, n;
    while (cin >> n >> m)
    {
        LL L = 1, R = n, mid;
        while (R - L > 0)
        {
            mid = (R + L) / 2;
            //LL k = f(mid, m);
            LL k = binaryPow(mid, m, maxn);
            if (k == n)
                break;
            if (k > n)
                R = mid;
            else
                L = mid;
        }
        printf("%d\n", mid);
    }
    system("pause");
    return 0;
}