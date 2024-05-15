#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < n-2; i++) {
      for (int j = i+1; j < n-1; j++) {
        ans += lower_bound(v.begin(), v.end(), v[i]+v[j])-v.begin()-j-1;
      }
    }
    cout << ans << endl;
}