#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x, maxans, minans, sum;
  cin >> n;
  vector<int> dp(n), dpi(n);
  if (n == 0) return 0;
  cin >> x;
  dp[0] = x;
  dpi[0] = x;
  maxans = x;
  minans = x;
  sum = x;
  for (int i = 1; i < n; i++) {
    cin >> x;
    sum += x;
    dp[i] = max(dp[i-1]+x, x);
    dpi[i] = min(dpi[i-1]+x, x);
    maxans = max(dp[i], maxans);
    minans = min(dpi[i], minans);
  }
  if (sum == minans)
    cout << maxans << "\n";
  else
    cout << max(maxans, sum-minans) << "\n";
}