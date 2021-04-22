#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n, in, out;
    string unlocked, locked;
    int minn = INT_MAX, maxn = INT_MIN;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int h1, m1, s1;
        int h2, m2, s2;
        string id;
        cin >> id;
        scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
        in = h1 * 60 * 60 + m1 * 60 + s1;
        out = h2 * 60 * 60 + m2 * 60 + s2;
        if (in < minn)
        {
            minn = in;
            unlocked = id;
        }
        if (out > maxn)
        {
            maxn = out;
            locked = id;
        }
    }
    cout << unlocked << " " << locked;
    return 0;
}
