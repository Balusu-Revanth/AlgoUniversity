#include <bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

int tile(int n, vector<int>& dp) {
  if (n <= 2) return n;
  if (dp[n] > 0) return dp[n];
  dp[n] = ((tile(n-1, dp)%M)+(tile(n-2, dp)%M));
  return dp[n];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> dp(n+1,0);
  cout << tile(n, dp);
}