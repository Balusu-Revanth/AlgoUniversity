#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	long long int m;
	cin >> m;
	long long int n = s.length();
	vector<int> sw(n/2+1, 0);
	for (long long int i = 0; i < m; i++) {
		long long int a;
		cin >> a;
		sw[a-1]++;
	}
	for (long long int i = 1; i < n/2; i++) {
		sw[i] += sw[i-1];
	}
	for (long long int i = 0; i < n/2; i++) {
		if (sw[i]%2 == 1) {
			swap(s[i], s[n-i-1]);
		}
	}
	cout << s;
}