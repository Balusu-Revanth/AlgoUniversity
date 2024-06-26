#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  string str;
  cin >> str;
  int n = str.size();
  vector<int> ans(n, -1);
  stack<int> s;
  for (int i = 0; i < n; i++) {
    if (str[i] == '(') {
      s.push(i);
    }
    else {
      if (!s.empty()) {
        ans[i] = s.top();
        ans[s.top()] = i;
        s.pop();
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
}