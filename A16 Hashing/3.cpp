#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int n, x, flag = 0;
  cin >> n;
  int psum = 0;
  unordered_set<int> s;
  s.insert(psum);
  for (int i = 0; i < n; i++) {
    cin >> x;
    psum += x;
    if (s.find(psum) != s.end()) {
      flag = 1; 
      break;
    }
    s.insert(psum);
  }
  flag ? cout << "YES" : cout << "NO";
}