#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<vector<int>> dp(n+1, vector<int> (n+1));
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        if (i == 0 || j == 0) {
          dp[i][j] = 0;
        }
        else {
          dp[i][j] = dp[i][j-1];
          if (i >= j) {
            dp[i][j] = max(dp[i][j], dp[i-j][j]+a[j-1]);
          }
        }
      }
    }
    cout << dp[n][n] << "\n";
  }
}