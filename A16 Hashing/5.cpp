#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x;
  cin >> n;
  set<int> s;
  for (int i = 0; i < n; i++) {
    cin >> x;
    s.insert(x);
  }
  int curr_ans = 1, final_ans = 1;
  x = -1;
  for (auto itr: s) {
    if (itr == x+1) {
      curr_ans++;
    }
    else {
      curr_ans = 1;
    }
    final_ans = max(final_ans, curr_ans);
    x = itr;
  }
  cout << final_ans;
}