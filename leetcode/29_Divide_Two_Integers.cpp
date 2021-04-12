#include <bits/stdc++.h>
using namespace std;
#define LIMIT 0x80000000
int divide(int dividend, int divisor)
{
    if (dividend == 0)
    {
        return 0;
    }
    if (dividend == INT_MIN && divisor == -1)
    {
        return INT_MAX;
    }
    long long t = fabs(dividend);
    long long d = fabs(divisor);
    long long result = 0;
    for (int i = 31; i >= 0; i--)
    {
        if ((t >> i) >= d)
        {                     //找出足够大的数2^n*divisor
            result += 1 << i; //将结果加上2^n
            t -= d << i;      //将被除数减去2^n*divisor
        }
    }
    if (result == LIMIT) //特殊数不能将unsigned int转为int
        return INT_MIN;
    return (dividend ^ divisor) < 0 ? -(long long)result : (long long)result;
}
int main()
{
    vector<int> nums = {0};
    cout << divide(-2147483648, 1) << endl;
    system("pause");
    return 0;
}