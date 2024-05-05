#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }
  int l = 0, r = n-1;
  while (l < r) {
    if (v[l] < v[r]) break;
    int m = l+(r-l)/2;
    if (v[m] >= v[l]) {
      l = m+1;
    }
    else {
      r = m;
    }
  }
  cout << v[l];
}