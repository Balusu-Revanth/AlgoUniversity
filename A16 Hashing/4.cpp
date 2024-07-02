#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> mp;
  
bool comp(int a, int b) {
  if (mp[a] == mp[b]) {
    return a < b;
  }
  return mp[a] > mp[b];
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  sort(a.begin(), a.end(), comp);
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}