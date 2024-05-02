#include <bits/stdc++.h>
using namespace std;

int main() {
  int d;
  cin >> d;
  vector<bool> hate(10, false);
  for (int i = 0; i < d; i++) {
    int x;
    cin >> x;
    hate[x] = true;
  }
  vector<int> validNums;
  for (int i = 0; i < 10; i++) {
    if (!hate[i]) validNums.push_back(i);
  }
  long long int n;
  cin >> n;
  int l = validNums.size();
  string ans;
  while (n > 0) {
    int i = n%l;
    ans = to_string(validNums[i]) + ans;
    n /= l;
  }
  cout << ans;
}