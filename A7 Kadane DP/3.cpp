#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x, ans1, ans2;
  cin >> n;
  vector<int> v(n), dplr(n), dprl(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  if (n == 0) return 0;
  if (n == 1) {
    cout << v[0] << "\n";
    return 0;
  }
  dplr[0] = v[0];
  ans1 = v[0];
  for (int i = 1; i < n; i++) {
    dplr[i] = max(dplr[i-1]+v[i], v[i]);
    ans1 = max(dplr[i], ans1);
  }
  dprl[n-1] = v[n-1];
  for (int i = n-2; i >= 0; i--) {
    dprl[i] = max(dprl[i+1]+v[i], v[i]);
  }
  ans2 = dprl[1];
  for (int i = 1; i < n-1; i++) {
    ans2 = max(dplr[i-1]+dprl[i+1], ans2);
  }
  ans2 = max(dplr[n-2], ans2);
  cout << max(ans1, ans2) << "\n";
}