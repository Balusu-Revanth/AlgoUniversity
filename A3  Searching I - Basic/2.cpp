#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
  long long int x;
  vector<long long int> arr;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> x;
    arr.push_back(x);
  }
  while (q--) {
    cin >> x;
    int l = -1, r = n;
    while (l+1 < r) {
      int m = l+(r-l)/2;
      if (arr[m] <= x) {
        l = m;
      }
      else {
        r = m;
      }
    }
    cout << l << " ";
  }
}