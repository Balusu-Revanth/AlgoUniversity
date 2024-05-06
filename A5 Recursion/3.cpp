#include <bits/stdc++.h>
using namespace std;

void perm(string s, string ans, vector<bool>& used) {
  if (ans.size() == s.size()) {
    cout << ans << "\n";
    return;
  }
  for (int i = 0; i < s.size(); i++) {
    if (used[i]) continue;
    ans += s[i];
    used[i] = true;
    perm(s, ans, used);
    ans.pop_back();
    used[i] = false;
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  int n = s.size();
  string ans = "";
  vector<bool> used(n,false);
  sort(s.begin(), s.end());
  perm(s, ans, used);
}