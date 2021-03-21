#include <bits/stdc++.h>
using namespace std;
char w[] = "0123456789ABC";
void fun(int i)
{
    int k = i, p = 0;
    char tmp[14];
    do
    {
        tmp[p++] = w[k % 13];
        k /= 13;
    } while (k > 0);
    if(p == 1) printf("0");
    for (int x = p - 1; x >= 0; x--)
    {
        printf("%c", tmp[x]);
    }
}
int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    printf("#");
    fun(r);
    fun(g);
    fun(b);
    printf("\n");
    return 0;
}