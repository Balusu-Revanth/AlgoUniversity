#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int n, m, x;
  cin >> n >> m;
  set<int> s;
  for (int i = 0; i < n+m; i++) {
    cin >> x;
    s.insert(x);
  }
  for (auto itr: s) {
    cout << itr << " ";
  }
}