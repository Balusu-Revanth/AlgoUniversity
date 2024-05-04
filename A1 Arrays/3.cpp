#include <bits/stdc++.h>
using namespace std;

int main() {
  long int n, w;
  cin >> n >> w;
  vector<pair<long int, long int>> prs;
  for (long int i = 0; i < n; i++) {
    long int x;
    cin >> x;
    prs.push_back(make_pair(x, i+1));
  }
  sort(prs.begin(), prs.end());
  long int l = 0, r = n - 1;
  while (l < r) {
    long int sum = prs[l].first + prs[r].first;
    if (sum < w) {
      l++;
    }
    else if (sum > w) {
      r--;
    }
    else {
      cout << prs[l].second << " " << prs[r].second;
      break;
    }
  }
  if (l == r) {
    cout << -1;
  }
}