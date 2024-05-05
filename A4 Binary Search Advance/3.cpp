#include <bits/stdc++.h>
using namespace std;

int pred(long int m, long int w, long int h, long int n) {
  return ((m/w)*(m/h) < n) ? 0 : 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long int w, h, n;
    cin >> w >> h >> n;
    long int l = 0, r = 1;
    while (pred(r, w, h, n) == 0) {
      r *= 2;
    }
    while (l+1 < r) {
      long int m = l+(r-l)/2;
      if (pred(m, w, h, n) == 0) l = m;
      else r = m;
    }
    cout << r << "\n";
  }
}