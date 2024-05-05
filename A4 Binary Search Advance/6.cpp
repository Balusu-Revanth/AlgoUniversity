#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<long long, long long>> coor;

int pred(long long d) {
  int ppl = 0, prev = -d;
  for (int i = 0; i < m; i++) {
    long long l = coor[i].first, r = coor[i].second;
    long long s = max(l, prev+d);
    if (r >= s) {
      int p = (r-s)/d + 1;
      ppl += p;
      prev = s+(p-1)*d;
    }
  }
  return (ppl >= n) ? 0 : 1;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    long long l, r;
    cin >> l >> r;
    coor.push_back({l, r});
  }
  sort(coor.begin(), coor.end());
  long long l = 0, r = pow(10,18)+1;
  while (l+1 < r) {
    long long mid = l+(r-l)/2;
    if (pred(mid) == 0) l = mid;
    else r = mid;
  }
  cout << l;
}