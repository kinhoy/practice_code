#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 记忆化搜索存储状态的数组
// -1 表示 false，1 表示 true，0 表示未计算
int memo[30][30][31];
string s1, s2;
bool checkIfSimilar(int i1, int i2, int length)
{
    unordered_map<int, int> freq;
    for (int i = i1; i < i1 + length; ++i)
    {
        ++freq[s1[i]];
    }
    for (int i = i2; i < i2 + length; ++i)
    {
        --freq[s2[i]];
    }
    if (any_of(freq.begin(), freq.end(), [](const auto &entry) { return entry.second != 0; }))
    {
        return false;
    }
    return true;
}

// 第一个字符串从 i1 开始，第二个字符串从 i2 开始，子串的长度为 length，是否和谐
bool dfs(int i1, int i2, int length)
{
    if (memo[i1][i2][length])
    {
        return memo[i1][i2][length] == 1;
    }

    // 判断两个子串是否相等
    if (s1.substr(i1, length) == s2.substr(i2, length))
    {
        memo[i1][i2][length] = 1;
        return true;
    }

    // 判断是否存在字符 c 在两个子串中出现的次数不同
    if (!checkIfSimilar(i1, i2, length))
    {
        memo[i1][i2][length] = -1;
        return false;
    }

    // 枚举分割位置
    for (int i = 1; i < length; ++i)
    {
        // 不交换的情况
        if (dfs(i1, i2, i) && dfs(i1 + i, i2 + i, length - i))
        {
            memo[i1][i2][length] = 1;
            return true;
        }
        // 交换的情况
        if (dfs(i1, i2 + length - i, i) && dfs(i1 + i, i2, length - i))
        {
            memo[i1][i2][length] = 1;
            return true;
        }
    }

    memo[i1][i2][length] = -1;
    return false;
}

bool isScramble(string s11, string s22)
{
    memset(memo, 0, sizeof(memo));
    s1 = s11;
    s2 = s22;
    return dfs(0, 0, s11.size());
}

int main()
{
    string ss1 = "abcde", ss2 = "caebd";
    cout << isScramble(ss1, ss2) << endl;
    system("pause");
    return 0;
}