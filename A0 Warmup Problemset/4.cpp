#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int x;
  cin >> x;
  x = abs(x);
  long long int n = 0, sum = 0;
  while (sum < x || (sum-x)%2 != 0) {
    n += 1;
    sum += n;
  }
  cout << n;
}