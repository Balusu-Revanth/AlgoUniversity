#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  unordered_map<int, int> mp;
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  cout << mp.size() << " ";
  for (int i = 0, j = k; j < n; i++, j++) {
    cin >> a[j];
    mp[a[j]]++;
    mp[a[i]]--;
    if (mp[a[i]] == 0) mp.erase(a[i]);
    cout << mp.size() << " ";
  }
}