#include <bits/stdc++.h>
using namespace std;

void toh(int n, int a, int b, int c) {
  if (n == 1) {
    cout << 1 << " " << a << " " << b << "\n";
    return;
  }
  toh(n-1, a, c, b);
  cout << n << " " << a << " " << b << "\n";
  toh(n-1, c, b, a);
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  if (n == 0) {
    cout << 0 << "\n";
    return 0;
  }
  cout << pow(2, n)-1 << "\n";
  toh(n, 1, 2, 3);
}