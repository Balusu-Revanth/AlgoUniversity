#include <bits/stdc++.h>
using namespace std;

int n, m, c;
vector<int> t;

int pred(int mid) {
  int buses = 1, first = t[0], currCap = 1;
  for (int i = 0; i < n; i++) {
    if (currCap > c || t[i]-first > mid) {
      buses++;
      currCap = 1;
      first = t[i];
    }
    currCap++;
  }
  return (buses > m) ? 0 : 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> c;
  int l = -1, r = -1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    t.push_back(x);
    r = max(r, x);
  }
  sort(t.begin(), t.end());
  while (l+1 < r) {
    int mid = l+(r-l)/2;
    if (pred(mid) == 0) l = mid;
    else r = mid;
  }
  cout << r;
}