#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, q, x;
  cin >> n >> m >> q;
  vector<vector<int>> arr;
  for (int i = 0; i < n; i++) {
    vector<int> row;
    for (int j = 0; j < m; j++) {
      cin >> x;
      row.push_back(x);
    }
    arr.push_back(row);
  }
  while (q--) {
    cin >> x;
    int l = -1, r = n*m;
    while (l+1 < r) {
      int mid = l+(r-l)/2;
      int i = mid/m, j = mid%m;
      if (arr[i][j] <= x) {
        l = mid;
      }
      else {
        r = mid;
      }
    }
    int i = l/m, j = l%m;
    cout << i << " " << j << "\n";
  }
}