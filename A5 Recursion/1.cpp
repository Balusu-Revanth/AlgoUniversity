#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
  if (n == 1 || n == 2) return 1;
  return fib(n-1)+fib(n-2);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  if (n == 0) {
    cout << 0;
    exit(0);
  }
  cout << fib(n);
}