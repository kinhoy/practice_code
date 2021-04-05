#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
int n, k, personNum = 0;
bool vis[maxn] = {false};
int weight[maxn] = {0};
int MAP[maxn][maxn] = {0};
map<string, int> GANG;
map<string, int> string2int;
map<int, string> int2string;
void dfs(int index, int &head, int &memberNum, int &sum)
{
    memberNum++;
    vis[index] = true;
    if (weight[index] > weight[head])
    {
        head = index;
    }
    for (int i = 0; i < personNum; i++)
    {
        if (MAP[index][i] > 0)
        {
            sum += MAP[index][i];
            MAP[index][i] = MAP[i][index] = 0;
            if (vis[i] == false)
                dfs(i, head, memberNum, sum);
        }
    }
}
void DFS()
{
    for (int i = 0; i < personNum; i++)
    {
        if (vis[i] == false)
        {
            int head = i, memberNum = 0, sum = 0;
            dfs(i, head, memberNum, sum);
            if (memberNum > 2 && sum > k)
                GANG[int2string[head]] = memberNum;
        }
    }
}
int getId(string str)
{
    if (string2int.find(str) != string2int.end())
    {
        return string2int[str];
    }
    else
    {
        string2int[str] = personNum;
        int2string[personNum] = str;
        return personNum++;
    }
}
int main()
{
    cin >> n >> k;
    string n1, n2;
    int time;
    for (int i = 0; i < n; i++)
    {
        cin >> n1 >> n2 >> time;
        int id1 = getId(n1);
        int id2 = getId(n2);
        weight[id1] += time;
        weight[id2] += time;
        MAP[id1][id2] += time;
        MAP[id2][id1] += time;
    }
    DFS();
    cout << GANG.size() << endl;
    for (auto it = GANG.begin(); it != GANG.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    // /system("pause");
    return 0;
}