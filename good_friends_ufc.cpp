//并查集
#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int father[maxn];
bool flag[maxn];
void init()
{
    for (int i = 0; i < maxn; i++)
    {
        father[i] = i;
    }
}
int findFather(int x)
{
    while (x != father[x])
    {
        x = father[x];
    }
    return x;
}
//路径压缩
int findFatherPathCompress(int x)
{
    int a = x;
    while (x != father[x])
    {
        x = father[x];
    }
    while (a != father[a])
    {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}
void Union(int a, int b)
{
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB)
        father[faA] = faB;
}
int main()
{
    init();
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        Union(a, b);
    }
    for (int i = 1; i <= n; i++)
    {
        flag[findFather(i)] = true;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += flag[i];
    }
    cout << ans << endl;
    system("pause");
    return 0;
}