#include <iostream>
#include <queue>
using namespace std;
const int maxn = 100;
struct node
{
    int x, y;
} Node;
int n, m;
int map[maxn][maxn];
bool is_visited[maxn][maxn] = {false};
int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};
bool judge(int x, int y)
{
    if (x >= n || x < 0 || y >= m || y < 0)
        return false;
    if (map[x][y] == 0 || is_visited[x][y] == true)
        return false;
    return true;
}
void BFS(int x, int y)
{
    queue<node> Q;
    Node.x = x;
    Node.y = y;
    is_visited[x][y] = true;
    Q.push(Node);
    while (!Q.empty())
    {
        node top = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = top.x + X[i];
            int ny = top.y + Y[i];
            if (judge(nx, ny))
            {
                Node.x = nx;
                Node.y = ny;
                Q.push(Node);
                is_visited[nx][ny] = true;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 1 && is_visited[i][j] == false)
            {
                ans++;
                BFS(i, j);
            }
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
