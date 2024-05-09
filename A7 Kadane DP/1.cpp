#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x, ans;
  cin >> n;
  vector<int> dp(n);
  if (n == 0) return 0;
  cin >> x;
  dp[0] = x;
  ans = x;
  for (int i = 1; i < n; i++) {
    cin >> x;
    dp[i] = max(dp[i-1]+x, x);
    ans = max(dp[i], ans);
  }
  cout << ans << endl;
}