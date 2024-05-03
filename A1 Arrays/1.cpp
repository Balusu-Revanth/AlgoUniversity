#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v, ans(n, 0);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  int l = 0, r = n-1, i = n-1;
  while (i >= 0) {
    if (abs(v[l]) < abs(v[r])) {
      ans[i] = v[r]*v[r];
      r--;
    }
    else {
      ans[i] = v[l]*v[l];
      l++;
    }
    i--;
  }
  for (int x: ans) {
    cout << x << " ";
  }
}