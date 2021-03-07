/* 1001 A+B Format */
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int m, n, sum;
    cin >> m >> n;
    sum = m + n;
    if (sum == 0)
    {
        printf("0\n");
        return 0;
    }
    int flag = sum < 0 ? -1 : 1;
    sum *= flag;
    char s[10];
    int i = 0, count = 0;
    while (sum > 0)
    {
        int j = sum % 10;
        s[i] = '0' + j;
        if (count > 0 && (count + 1) % 3 == 0 && sum / 10 > 0)
        {
            s[++i] = ',';
        }
        i++;
        count++;
        sum /= 10;
    }
    if (flag == -1)
        printf("%c", '-');
    while (i--)
    {
        printf("%c", s[i]);
    }
    printf("\n");
    return 0;
}