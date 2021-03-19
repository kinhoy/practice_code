/* 1041 Be Unique */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, temp, num[100001], count[10001];
    scanf("%d", &n);
    int p = n;
    while (n--)
    {
        scanf("%d", &temp);
        num[n] = temp;
        count[temp]++;
    }
    int flag = 1;
    while (p--)
    {
        if (count[num[p]] == 1)
        {
            printf("%d\n", num[p]);
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        printf("None\n");
    }
    return 0;
}