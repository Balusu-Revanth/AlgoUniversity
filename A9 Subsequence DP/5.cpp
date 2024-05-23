#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  const int M = 1e9 + 7;
  vector<long long> dp(n+1, 1);
  long long neg = 1, neb = 0;
  for (int i = 1; i < n; i++) {
    if (i % 2 == 0) {
      dp[i] = (dp[i]+neb) % M;
      neg = (neg+dp[i]) % M;
    }
    else {
      dp[i] = (dp[i]+neg) % M;
      neb = (neb+dp[i]) % M;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = (ans+dp[i]) % M;
  }
  cout << ans << "\n";
}