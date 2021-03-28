#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> num[i];
    }
    if (num[0] > 0)
    {
        for (int i = 1; i < 10; i++)
        {
            if (num[i] > 0)
            {
                cout << i;
                num[i]--;
                break;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (num[i] > 0)
            for (int j = 0; j < num[i]; j++)
                cout << i;
    }
    system("pause");
    return 0;
}