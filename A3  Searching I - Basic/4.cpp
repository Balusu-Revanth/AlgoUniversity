#include <bits/stdc++.h>
using namespace std;

int main() {
  double n;
  cin >> n;
  double l = 0, r = n, e = pow(10, -6);
  while (l+e < r) {
    double m = l+(r-l)/2;
    if (m*m <= n) {
      l = m;
    }
    else {
      r = m;
    }
  }
  cout << setprecision(15) << l;
}