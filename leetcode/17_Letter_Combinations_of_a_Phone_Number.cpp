#include <bits/stdc++.h>
using namespace std;
vector<string> add(vector<string> prex, string current[])
{
    vector<string> n;
    for (int i = 0; i < prex.size(); i++)
    {
        for (int j = 0; j < 4 && current[j] != "#"; j++)
        {
            n.push_back(prex[i] + current[j]);
        }
    }
    return n;
}
vector<string> letterCombinations(string digits)
{
    string c[8][4] = {"a", "b", "c", "#",
                      "d", "e", "f", "#",
                      "g", "h", "i", "#",
                      "j", "k", "l", "#",
                      "m", "n", "o", "#",
                      "p", "q", "r", "s",
                      "t", "u", "v", "#",
                      "w", "x", "y", "z"};
    vector<string> prex;
    if (digits.length() == 0)
        return prex;
    int first = digits[0] - '0' - 2;
    for (int i = 0; i < 4 && c[first][i] != "#"; i++)
    {
        prex.push_back(c[first][i]);
    }
    for (int i = 1; i < digits.length() && digits.length() > 1; i++)
    {
        prex = add(prex, c[digits[i] - '0' - 2]);
    }
    return prex;
}

int main()
{
    vector<string> ad = letterCombinations("333");
    for (int i = 0; i < ad.size(); i++)
    {
        cout << ad[i] << " ";
    }
    system("pause");
    return 0;
}