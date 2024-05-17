#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test;
  cin >> test;
  while (test--) {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<vector<int>> dp(n+1, vector<int> (m+1));
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        if (i == 0 || j == 0) {
          dp[i][j] = i+j;
        }
        else {
          if (s[i-1] == t[j-1]) {
            dp[i][j] = dp[i-1][j-1];
          }
          else {
            dp[i][j] = 1 + min(dp[i-1][j-1], (min(dp[i][j-1], dp[i-1][j])));
          }
        }
      }
    }
    cout << dp[n][m] << "\n";
  }
}