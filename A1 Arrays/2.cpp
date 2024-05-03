#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  set<int> s;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s.insert(x);
  }
  int a = 1;
  for (auto x: s) {
    if (x != a) {
      cout << a;
      exit(0);
    }
    a++;
  }
  cout << a;
}