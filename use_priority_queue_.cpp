#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//升序队列
//priority_queue<int, vector<int>, greater<int>> q;
//降序队列
//priority_queue<int, vector<int>, less<int>> q;
struct tmp1 //运算符重载<
{
    int x;
    tmp1(int a) { x = a; }
    bool operator<(const tmp1 &a) const
    {
        return x < a.x; //大顶堆
    }
};
struct tmp2 //重写仿函数
{
    bool operator()(tmp1 a, tmp1 b)
    {
        return a.x < b.x; //大顶堆
    }
};
struct cmp
{
    template <typename T, typename U>
    bool operator()(T const &left, U const &right)
    {
        // 以second比较。输出结果为Second较大的在前Second相同时，先进入队列的元素在前。
        if (left.second < right.second)
            return true;
        return false;
    }
};
int main()
{
    //对于基础类型 默认是大顶堆
    priority_queue<int> a;
    //等同于 priority_queue<int, vector<int>, less<int> > a;
    priority_queue<int, vector<int>, greater<int>> c;
    priority_queue<string> b;

    for (int i = 0; i < 5; i++)
    {
        a.push(i);
        c.push(i);
    }
    cout << "less " << endl;
    while (!a.empty())
    {
        cout << a.top() << ' ';
        a.pop();
    }
    cout << endl;

    cout << "greater " << endl;
    while (!c.empty())
    {
        cout << c.top() << ' ';
        c.pop();
    }
    cout << endl;

    b.push("abc");
    b.push("abcd");
    b.push("cbd");
    while (!b.empty())
    {
        cout << b.top() << ' ';
        b.pop();
    }
    cout << endl;

    priority_queue<pair<int, int>> ap; //less
    //priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> ap; //greater
    //priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> ap; //self-cmp
    pair<int, int> bp(1, 2);
    pair<int, int> cp(1, 3);
    pair<int, int> dp(2, 5);
    ap.push(dp);
    ap.push(cp);
    ap.push(bp);
    while (!ap.empty())
    {
        cout << ap.top().first << ' ' << ap.top().second << '\n';
        ap.pop();
    }

    tmp1 aa(1);
    tmp1 bb(2);
    tmp1 cc(3);
    priority_queue<tmp1> d;
    d.push(bb);
    d.push(cc);
    d.push(aa);
    while (!d.empty())
    {
        cout << d.top().x << '\n';
        d.pop();
    }
    cout << endl;

    priority_queue<tmp1, vector<tmp1>, tmp2> f;
    f.push(cc);
    f.push(bb);
    f.push(aa);
    while (!f.empty())
    {
        cout << f.top().x << '\n';
        f.pop();
    }
    system("pause");
    return 0;
}