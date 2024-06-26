#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> h(n), l(n, -1), r(n, n);
  stack<pair<int, int>> s;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
    while (!s.empty() && h[i] <= s.top().first) s.pop();
    if (!s.empty()) {
      l[i] = s.top().second;
    }
    s.push({h[i], i});
  }
  s = stack<pair<int, int>>();
  int ans = 0;
  for (int i = n-1; i >= 0; i--) {
    while (!s.empty() && h[i] <= s.top().first) s.pop();
    if (!s.empty()) {
      r[i] = s.top().second;
    }
    s.push({h[i], i});
    ans = max(ans, h[i]*(r[i]-l[i]-1));
  }
  cout << ans;
}