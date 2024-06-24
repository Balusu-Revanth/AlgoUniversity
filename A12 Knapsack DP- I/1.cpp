#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, c;
  cin >> n >> c;
  vector<int> cost(n), profit(n);
  for (int i = 0; i < n; i++) {
    cin >> cost[i] >> profit[i];
  }
  vector<vector<int>> dp(n+1, vector<int> (c+1));
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= c; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
      }
      else {
        dp[i][j] = dp[i-1][j];
        if (j >= cost[i-1]) {
          dp[i][j] = max(dp[i][j], dp[i-1][j-cost[i-1]] + profit[i-1]);
        }
      }
    }
  }
  cout << dp[n][c] << "\n";
}