#include <iostream>
#include <algorithm>
using namespace std;
int n, m, c1, c2;
int e[510][510], weight[510], dis[510], num[510], w[510];
bool visit[510];
const int inf = 1e8 - 1;
int main()
{
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    for (int i = 0; i < n; i++)
        scanf("%d", &weight[i]);
    fill(e[0], e[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        e[a][b] = e[b][a] = c;
    }
    dis[c1] = 0;
    w[c1] = weight[c1];
    num[c1] = 1;
    for (int i = 0; i < n; i++)
    {
        int u = -1, minn = inf;
        for (int j = 0; j < n; j++)
        {
            if (visit[j] == false && dis[j] < minn)
            {
                u = j;
                minn = dis[j];
            }
        }
        if (u == -1)
            break;
        visit[u] = true;
        for (int v = 0; v < n; v++)
        {
            if (visit[v] == false && e[u][v] != inf)
            {
                if (dis[u] + e[u][v] < dis[v])
                {
                    dis[v] = dis[u] + e[u][v];
                    num[v] = num[u];
                    w[v] = w[u] + weight[v];
                }
                else if (dis[u] + e[u][v] == dis[v])
                {
                    num[v] = num[v] + num[u];
                    if (w[u] + weight[v] > w[v])
                        w[v] = w[u] + weight[v];
                }
            }
        }
    }
    printf("%d %d", num[c2], w[c2]);
    return 0;
}



/*
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#define MaxSize 500
int Graph[MaxSize][MaxSize];          //存放图
int vis[MaxSize] = {0}, dis[MaxSize]; //存放访问标记和路径长度,并不需要存储路径
int curNum[MaxSize] = {0};            //存放当前的城市医疗队
int n, m, cur, des;                   //城市个数，m为路径，cur为目前所在城市，des为目标城市
const int INF = 0x7fffffff;           //定义一个很大的数
//定义一个容器，存放到达当前站点的最多医疗数
vector<int> vec[MaxSize];
//输入函数
void Input()
{
    cin >> n >> m >> cur >> des;
    int i;
    int x, y, z;
    memset(Graph, -1, sizeof(Graph));
    for (i = 0; i < n; i++)
    {
        dis[i] = MaxSize;
    }
    for (i = 0; i < n; i++)
    {
        cin >> curNum[i];
    }
    for (i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        Graph[x][y] = z;
        Graph[y][x] = z;
    }
}
void push(int target, int dataid) //将当前dataid统计的数据送到target
{
    for (int i = 0; i < vec[dataid].size(); i++)
    {
        vec[target].push_back(vec[dataid][i] + curNum[target]);
    }
}
void Dij(int source, int destination)
{
    vis[source] = 1;
    dis[source] = 0;
    //将初始起点放进容器
    vec[source].push_back(curNum[source]);
    int i;
    int cen = source;
    int Min;
    while (1)
    {
        //1、找到cen相邻的点并且未访问
        for (i = 0; i < n; i++)
        {
            if (vis[i] == 0 && Graph[cen][i] != -1)
            {
                if (dis[cen] + Graph[cen][i] < dis[i])
                {
                    dis[i] = dis[cen] + Graph[cen][i];
                    vec[i].clear(); //将对应的值清空
                    push(i, cen);
                }
                else if (dis[cen] + Graph[cen][i] == dis[i]) //相等，说明是多条路径
                {
                    push(i, cen);
                }
            }
        }
        //2、找到下一个节点
        Min = INF;
        for (i = 0; i < n; i++)
        {
            if (vis[i] == 0 && Min > dis[i])
            {
                cen = i;
                Min = dis[i];
            }
        }
        vis[cen] = 1;
        if (cen == destination)
        {
            break;
        }
    }
}
int main()
{
    Input();
    int i, j;
    if (n == 0)
    {
        cout << "0 0" << endl;
        return 0;
    }
    else if (cur == des)
    {
        cout << "1 " << curNum[cur];
        return 0;
    }
    else
    {
        Dij(cur, des);
        vector<int> tt = vec[des];
        cout << tt.size() << ' ';
        j = tt[0];
        for (i = 1; i < tt.size(); i++)
        {
            if (j < tt[i])
            {
                j = tt[i];
            }
        }
        cout << j;
    }
    system("pause");
    return 0;
}
*/