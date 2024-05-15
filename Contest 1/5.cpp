#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;
    vector<int> pos[26];
    for (int i = 0; i < b.size(); i++) {
      pos[b[i]-'A'].push_back(i);
    }
    int ans = 1, index = -1;
    for (int i = 0; i < a.size(); i++) {
      int j = a[i]-'A';
      if (pos[j].size() == 0) {
        ans = -1;
        break;
      }
      auto itr = upper_bound(pos[j].begin(), pos[j].end(), index);
      if (itr != pos[j].end()) {
        index = *itr;
      } else {
        ans++;
        index = pos[j][0];
      }
    }
    cout << ans << "\n";
  }
}