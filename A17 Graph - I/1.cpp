#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int n, x;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cout << i << ": ";
    for (int j = 1; j <= n; j++) {
      cin >> x;
      if (x == 1) cout << j << " ";
    }
    cout << "\n";
  }
}