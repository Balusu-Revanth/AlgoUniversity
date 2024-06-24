#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int c, m, n, z, o;
  cin >> c >> m >> n;
  vector<int> zeroes(c);
  vector<int> ones(c);
  string s;
  for (int i = 0; i < c; i++) {
    cin >> s;
    z = 0;
    o = 0;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == '0') z++;
      if (s[j] == '1') o++;
    }
    zeroes[i] = z;
    ones[i] = o;
  }
  vector<vector<vector<int>>> dp(c+1, vector<vector<int>> (m+1, vector<int> (n+1)));
  for (int i = 0; i <= c; i++) {
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k <= n; k++) {
        if (i == 0) {
          dp[i][j][k] = 0;
        }
        else {
          dp[i][j][k] = dp[i-1][j][k];
          if (j >= zeroes[i-1] && k >= ones[i-1]) {
            dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-zeroes[i-1]][k-ones[i-1]] + 1);
          }
        }
      }
    }
  }
  cout << dp[c][m][n] << "\n";
}