#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  const int M = 1e9+7;
  int t;
  cin >> t;
  while (t--) {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<vector<long long int>> dp(s+1, vector<long long int> (n+1));
    for (int i = 0; i <= s; i++) {
      for (int j = 0; j <= n; j++) {
        if (i == 0) {
          dp[i][j] = 1;
        }
        else if (j == 0) {
          dp[i][j] = 0;
        }
        else {
          dp[i][j] = dp[i][j-1];
          if (i >= a[j-1]) {
            dp[i][j] = (dp[i][j] + dp[i-a[j-1]][j]) % M;
          }
        }
      }
    }
    cout << dp[s][n] << "\n";
  }
}