#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, ans = 0;
    cin >> n;
    while (n > 0) {
      int a = n%10;
      ans = ans*10+a;
      n /= 10;
    }
    cout << ans << endl;
  }
}