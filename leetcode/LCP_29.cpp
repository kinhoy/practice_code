#include <bits/stdc++.h>
using namespace std;
int orchestraLayout(int num, int xPos, int yPos)
{
    long long x = xPos, y = yPos, n = num;
    if (x <= y)
    {
        long long k = min(x, n - 1 - y);
        return (4 * k * (n - k) + 1 + (x + y - k * 2) - 1) % 9 + 1;
    }
    long long kp = min(y, n - 1 - x) + 1;
    return (4 * kp * (n - kp) + 1 - (x + y - (kp - 1) * 2) - 1) % 9 + 1;
}