/* 1100 Mars Numbers */
#include <iostream>
using namespace std;
string low[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string high[] = {"***", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
void fun1(string s)
{
    int t = stoi(s);
    if (t / 13)
        cout << high[t / 13];
    if ((t / 13) && (t % 13))
        cout << " ";
    if (t % 13 || t == 0)
        cout << low[t % 13];
    cout << endl;
}
void fun2(string s)
{
    int t1 = 0, t2 = 0;
    string s1 = s.substr(0, 3), s2;
    if (s.length() > 4)
        s2 = s.substr(4, 3);
    for (int j = 1; j <= 12; j++)
    {
        if (s1 == low[j] || s2 == low[j])
            t2 = j;
        if (s1 == high[j])
            t1 = j;
    }
    cout << t1 * 13 + t2 << endl;
}

int main()
{
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        (s[0] >= '0' && s[0] <= '9') ? fun1(s) : fun2(s);
    }
    system("pause");
    return 0;
}