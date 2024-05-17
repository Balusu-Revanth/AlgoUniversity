#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, sum = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (sum % 2 != 0) {
      cout << "NO" << "\n";
      continue;
    }
    vector<vector<bool>> dp(sum/2+1, vector<bool> (n+1));
    for (int i = 0; i <= sum/2; i++) {
      for (int j = 0; j <= n; j++) {
        if (i == 0) {
          dp[i][j] = true;
        }
        else if (j == 0) {
          dp[i][j] = false;
        }
        else {
          dp[i][j] = dp[i][j-1];
          if (i >= a[j-1]) {
            dp[i][j] = dp[i][j] || dp[i-a[j-1]][j-1];
          }
        }
      }
    }
    dp[sum/2][n] ? cout << "YES\n" : cout << "NO\n";
  }
}