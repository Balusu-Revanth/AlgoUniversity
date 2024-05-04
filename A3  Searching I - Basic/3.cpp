#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long int> arr;

int pred1(int m, long long int x) {
  if (arr[m] < x) return 0;
  else return 1;
}

int pred2(int m, long long int x) {
  if (arr[m] <= x) return 0;
  else return 1;
}

pair<int, int> binarySearch(long long int x, int(*pred)(int, long long int)) {
  int l = -1, r = n;
  while (l+1 < r) {
    int m = l+(r-l)/2;
    if (pred(m,x) == 0) {
      l = m;
    }
    else {
      r = m;
    }
  }
  pair<int, int> p = {l, r};
  return p;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  long long int x;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> x;
    arr.push_back(x);
  }
  while (q--) {
    cin >> x;
    pair<int, int> p = binarySearch(x, &pred1);
    if (p.second < n && arr[p.second] == x) {
      cout << p.second << " ";
      p = binarySearch(x, &pred2);
      cout << p.first;
    }
    else {
      cout << "-1 -1";
    }
    cout << "\n";
  }
}