#include <bits/stdc++.h>
#include <vector> // Add this line

using namespace std;

bool isPrime[20] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1};
int ans = 0;

void perm(vector<int>& v, int i, int n) {
  if (i == n-1) {
    for (int j = 0; j < n; j++) {
      if (!isPrime[v[j]+v[(j+1)%n]]) return;
    }
    ans++;
    return;
  }
  for (int j = i; j < n; j++) {
    swap(v[i], v[j]);
    perm(v, i+1, n);
    swap(v[i], v[j]);
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  if (n & 1 || n == 0) {
    cout << 0 << endl;
    return 0;
  }
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    v[i] = i+1;
  }
  perm(v, 0, n);
  cout << ans / n << endl;
  return 0;
}