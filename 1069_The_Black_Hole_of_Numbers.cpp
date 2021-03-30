#include <bits/stdc++.h>
using namespace std;
#define len 4
void to_array(int n, int num[])
{
    for (int i = 0; i < len; i++)
    {
        num[i] = n % 10;
        n /= 10;
    }
}
bool cmp(int a, int b)
{
    return a > b; //less
}
int to_number(int num[])
{
    int sum = 0;
    for (int i = 0; i < len; i++)
        sum = sum * 10 + num[i];
    return sum;
}
int main()
{
    int num[len + 1];
    int n, MIN, MAX;
    scanf("%d", &n);
    while (1)
    {
        to_array(n, num);
        sort(num, num + len, cmp);
        MAX = to_number(num);
        sort(num, num + len);
        MIN = to_number(num);
        n = MAX - MIN;
        printf("%04d - %04d = %04d\n", MAX, MIN, n);
        if (n == 0 || n == 6174)
            break;
    }
    return 0;
}