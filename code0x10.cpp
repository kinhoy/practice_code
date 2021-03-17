/* 1023 Have Fun with Numbers */
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