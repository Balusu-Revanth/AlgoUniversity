#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    cin >> x;
    arr.push_back(x);
  }
  int l = -1, r = n;
  while (l+1 < r) {
    int mid = l+(r-l)/2;
    if (arr[mid] == 0) {
      l = mid;
    }
    else {
      r = mid;
    }
  }
  cout << r << " " << l;
}