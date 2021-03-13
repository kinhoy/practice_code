#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d;
    int num[10000] = {0};
    int len = 0;
    cin >> n >> d;
    do
    {
        num[len++] = n % d;
        n /= d;
    } while (n != 0);
    int j = len - 1;
    int flag = 1;
    for (int i = 0; i != j; i++)
    {
        if (num[i] != num[j])
        {
            flag = 0;
            break;
        }
        else
            j--;
    }
    if (!flag)
        printf("No\n");
    else
        printf("Yes\n");
    printf("%d", num[len - 1]);
    for (int i = len - 2; i >= 0; i--)
    {
        printf(" %d", num[i]);
    }
    printf("\n");
    return 0;
}