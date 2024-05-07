#include <bits/stdc++.h>
using namespace std;

const int M = 1e9+7;
int n;

int profit(int l, int r, vector<int>& p, vector<vector<int>>& dp) {
  int y = n-(r-l);
  if (l > r) return 0;
  if (dp[l][r] > 0) return dp[l][r];
  dp[l][r] = max(((profit(l+1,r,p,dp)%M)+(p[l]*y)%M)%M, ((profit(l,r-1,p,dp))%M+(p[r]*y)%M)%M);
  return dp[l][r];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  vector<vector<int>> dp(n, vector<int>(n,0));
  cout << profit(0, n-1, p, dp) << endl;
}