#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
      }
      else if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  string ans;
  int i = n, j = m;
  while (i > 0 && j > 0) {
    if (s[i-1] == t[j-1]) {
      ans = s[i-1] + ans;
      i--;
      j--;
    }
    else if (dp[i-1][j] > dp[i][j-1]) {
      i--;
    }
    else {
      j--;
    }
  }
  cout << ans << "\n";
}