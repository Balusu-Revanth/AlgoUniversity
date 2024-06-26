#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int n;
  cin >> n;
  stack<int> s;
  vector<int> a(n), ans(n, -1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    while (!s.empty() && s.top() <= a[i]) s.pop();
    if (!s.empty()) {
      ans[i] = s.top();
    }
    s.push(a[i]);
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
}