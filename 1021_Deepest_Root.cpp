#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
bool visited[10010];
int maxdepth = 0;
vector<vector<int>> v;
vector<int> queue;
set<int> s;
void dfs(int p, int depth)
{
    if (depth > maxdepth)
    {
        queue.clear();
        queue.push_back(p);
        maxdepth = depth;
    }
    else if (depth == maxdepth)
    {
        queue.push_back(p);
    }
    visited[p] = true;
    for (int i = 0; i < v[p].size(); i++)
    {
        if (!visited[v[p][i]])
            dfs(v[p][i], depth + 1);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int x, y, s1 = 0;
    v.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i, 1);
            if (i == 1)
            {
                if (queue.size() != 0)
                    s1 = queue[0];
                for (int j = 0; j < queue.size(); j++)
                    s.insert(queue[j]);
            }
            count++;
        }
    }
    if (count >= 2)
        printf("Error: %d components", count);
    else
    {
        queue.clear();
        maxdepth = 0;
        fill(visited, visited + 10010, false);
        dfs(s1, 1);
        for (int i = 0; i < queue.size(); i++)
            s.insert(queue[i]);
        for (auto it = s.begin(); it != s.end(); it++)
            printf("%d\n", *it);
    }
    system("pause");
    return 0;
}