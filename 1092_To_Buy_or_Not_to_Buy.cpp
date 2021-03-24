#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<char, int> mp1, mp2;
    string s1, s2;
    set<char> t;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++)
    {
        mp1[s1[i]]++;
    }
    for (int i = 0; i < s2.length(); i++)
    {
        mp2[s2[i]]++;
        t.insert(s2[i]);
    }
    int count = 0;
    for (auto iter = t.begin(); iter != t.end(); ++iter)
    {
        if (mp2[*iter] > mp1[*iter])
            count += (mp2[*iter] - mp1[*iter]);
    }
    if (count != 0)
    {
        cout << "No " << count << endl;
    }
    else
    {
        cout << "Yes " << s1.length() - s2.length() << endl;
    }
    return 0;
}
/*
#include <iostream>
using namespace std;
int book[256];
int main() {
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++)
        book[a[i]]++;
    int result = 0;
    for (int i = 0; i < b.length(); i++) {
        if (book[b[i]] > 0)
            book[b[i]]--;
        else
            result++;
    }
    if(result != 0)
        printf("No %d", result);
    else
        printf("Yes %d", a.length() - b.length());
    return 0;
}
*/