#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  if (n == 0) exit(0);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> dp(n);
  dp[0] = 1;
  int ans = 1;
  for (int i = 1; i < n; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (a[i]%a[j] == 0) {
        dp[i] = max(dp[i], dp[j]+1);
      }
    }
    ans = max(ans, dp[i]);
  }
  cout << ans << "\n";
}