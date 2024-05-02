#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y, a, b;
  cin >> x >> y >> a >> b;
  cout << min(min(abs(x-a)+abs(y-b), abs(x-b)+abs(y-a)), abs(x-y));
}