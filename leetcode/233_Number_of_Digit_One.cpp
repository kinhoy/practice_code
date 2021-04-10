#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int countDigitOne(int n)
{
    if (n < 1)
        return 0;
    int len = to_string(n).length();
    if (len == 1)
        return 1;
    int tmp = (int)pow(10, len - 1);
    int first = n / tmp;                              // 获取n的最高位数字
    int firstOneNum = first == 1 ? n % tmp + 1 : tmp; // 获取n的最高位为1时有多少个数字
    int otherOneNUm = first * (len - 1) * (tmp / 10); // 在介于n % tmp到n之间的数字中，除了最高位为1，其余各个数字分别为1的总数和
    return firstOneNum + otherOneNUm + countDigitOne(n % tmp);
}
int main()
{
    cout << countDigitOne(100) << endl;
    system("pause");
    return 0;
}