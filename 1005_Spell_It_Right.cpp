#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s, ss[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    while (cin >> s)
    {
        int sum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            sum += s[i] - '0';
        }
        s = to_string(sum);
        cout << ss[s[0] - '0'];
        for (int i = 1; i < s.length(); i++)
        {
            cout << " " << ss[s[i] - '0'];
        }
        cout << endl;
    }
    return 0;
}