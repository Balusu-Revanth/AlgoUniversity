#include <bits/stdc++.h>
using namespace std;

long long int minDiff (vector<long long int>& v, long long int tsum, long long int csum, int i) {
  if (i == v.size()) return abs((tsum-csum)-csum);
  return min(minDiff(v, tsum, csum+v[i], i+1), minDiff(v, tsum, csum, i+1));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  if (n == 0) return 0;
  vector<long long int> v(n);
  long long int tsum = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    tsum += v[i];
  }
  cout << minDiff(v, tsum, 0, 0) << "\n";
}