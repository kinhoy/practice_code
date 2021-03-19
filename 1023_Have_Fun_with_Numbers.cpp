#include <cstdio>
#include <string.h>
using namespace std;
int book[10];
int main()
{
    char num[22];
    scanf("%s", num);
    int flag = 0, len = strlen(num);
    for (int i = len - 1; i >= 0; i--)
    {
        int temp = num[i] - '0';
        book[temp]++;
        temp = temp * 2 + flag;
        flag = 0;
        if (temp >= 10)
        {
            temp = temp - 10;
            flag = 1;
        }
        num[i] = (temp + '0');
        book[temp]--;
    }
    int flag1 = 0;
    for (int i = 0; i < 10; i++)
    {
        if (book[i] != 0)
        {
            flag1 = 1;
            break;
        }
    }
    printf("%s", (flag == 1 || flag1 == 1) ? "No\n" : "Yes\n");
    if (flag == 1)
        printf("1");
    printf("%s", num);
    return 0;
}
/*
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	string s1,s2;
	cin >> s1;
	int r = 0;
	for (int i = s1.length() - 1; i >= 0; i--) {
		int a = (s1[i] - '0')*2 + r;
		s2 += to_string(a % 10);
		r = a / 10;
	}
	if (r != 0)
		s2 += to_string(r);
	int flag = 1;
	vector<int> arr(10), arr2(10);
	for (int i = 0; i < s1.length(); i++) 
		arr[s1[i] - '0']++;
	for (int i = 0; i < s2.length(); i++) 
		arr2[s2[i] - '0']++;
	for (int i = 0; i < 10; i++) {
		if (arr[i] != arr2[i]) {
			flag = 0; break;
		}
	}
	if (flag) 
		printf("Yes\n");
	else 
		printf("No\n");
	for (int i = s2.length()-1; i >= 0; i--)
		printf("%c", s2[i]);
	return 0;
}
*/