#include <bits/stdc++.h>
using namespace std;

int pred(long long mid, int m, vector<int>& v) {
  long long num = 0, child = 0;
  for (int i = 0; i < v.size(); i++) {
    if (num+v[i] <= mid) {
      num += v[i];
    }
    else {
      child++;
      num = v[i];
    }
  }
  child++;
  return (child > m) ? 0 : 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  long long l = 0, r = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    r += v[i];
    l = max(l, (long long)v[i]);
  }
  l--;
  if (n < m) {
    cout << -1;
    exit(0);
  }
  while (l+1 < r) {
    long long mid = l+(r-l)/2;
    if (pred(mid, m, v) == 0) l = mid;
    else r = mid;
  }
  cout << r;
}