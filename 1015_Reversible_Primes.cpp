/* 1015_Reversible_Primes */
#include <bits/stdc++.h>
using namespace std;
bool is_prime(int n)
{
    if (n <= 1)
        return false;
    int sqr = (int)sqrt(n);
    for (int i = 2; i <= sqr; i++)
        if (n % i == 0)
            return false;
    return true;
}
int main()
{
    int n, d;
    while (cin >> n)
    {
        int num[10000] = {0};
        int len;
        if (n < 0)
            break;
        cin >> d;
        if (!is_prime(n))
            cout << "No" << endl;
        else
        {
            len = 0;
            do
            {
                num[len++] = n % d;
                n /= d;
            } while (n != 0);
            for (int i = 0; i < len; i++)
                n = n * d + num[i];
            if (!is_prime(n))
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
    }
}