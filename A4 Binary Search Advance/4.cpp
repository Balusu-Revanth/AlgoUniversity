#include <bits/stdc++.h>
using namespace std;

long int n, h;
vector<long int> a;

int pred(long int m) {
  long int ops = 0;
  for (int i = 0; i < n; i++) {
    ops += ceil(a[i]*1.0/m);
  }
  return (ops > h) ? 0 : 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> h;
  long int l = 0, r = -1;
  for (int i = 0; i < n; i++) {
    long int x;
    cin >> x;
    a.push_back(x);
    r = max(r, x);
  }
  while (l+1 < r) {
    long int m = l+(r-l)/2;
    if (pred(m) == 0) l = m;
    else r = m;
  }
  cout << r;
}