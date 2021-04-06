#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1010;
struct Node
{
    int v;     //编号
    int layer; //顶点层数
};
bool inQueue[maxn];
vector<Node> Adj[maxn];
int stater[maxn];
int n, l;
int memberNum;
int maxDeep = -1;
void BFS(int s)
{
    memberNum = 0;
    queue<Node> q;
    Node begin;
    begin.v = s;
    begin.layer = 0;
    q.push(begin);
    inQueue[begin.v] = true;
    while (!q.empty())
    {
        Node top = q.front();
        q.pop();
        int u = top.v;
        for (int i = 0; i < Adj[u].size(); i++)
        {
            Node next = Adj[u][i];
            next.layer = top.layer + 1;
            if (inQueue[next.v] == false && next.layer <= l)
            {
                memberNum++;
                q.push(next);
                inQueue[next.v] = true;
                if (next.layer > maxDeep)
                    maxDeep = next.layer;
            }
        }
    }
}
int main()
{
    cin >> n >> l;
    int num, tmp;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        Node node;
        node.v = i;
        while (num--)
        {
            cin >> tmp;
            Adj[tmp].push_back(node);
        }
    }
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        BFS(tmp);
        cout << memberNum << endl;
        memset(inQueue, false, sizeof(inQueue));
    }
    // system("pause");
    return 0;
}