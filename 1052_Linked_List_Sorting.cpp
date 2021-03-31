#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
struct Node
{
    int address;
    int data;
    int next;
    bool flag;
} node[maxn];
bool cmp(Node a, Node b)
{
    if (a.flag == false || b.flag == false)
        return a.flag > b.flag;
    else
        return a.data < b.data;
}
int main()
{
    for (int i = 0; i < maxn; i++)
        node[i].flag = false;
    int s, n;
    int address, next;
    int data;
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &address, &data, &next);
        node[address].data = data;
        node[address].next = next;
        node[address].address = address;
    }
    int c = 0, p = s;
    while (p != -1)
    {
        node[p].flag = true;
        c++;
        p = node[p].next;
    }
    if (!c)
        printf("0 -1");
    else
    {
        sort(node, node + maxn, cmp);
        printf("%d %05d\n", c, node[0].address);
        for (int i = 0; i < c; i++)
        {
            if (i != c - 1)
                printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
            else
                printf("%05d %d -1\n", node[i].address, node[i].data);
        }
    }

    return 0;
}