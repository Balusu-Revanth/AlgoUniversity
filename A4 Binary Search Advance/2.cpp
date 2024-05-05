#include <bits/stdc++.h>
using namespace std;

int pred(long long m, long long n) {
  return (m*(m+1)/2 <= n) ? 0 : 1; 
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  long long l = 0, r = 1;
  while (pred(r, n) == 0) {
    r *= 2;
  }
  while (l+1 < r) {
    int m = l+(r-l)/2;
    if (pred(m, n) == 0) l = m;
    else r = m;
  }
  cout << l;
}