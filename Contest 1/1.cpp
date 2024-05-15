#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    vector<int> v(128, 0);
    for (int i = 0; i < s.size(); i++) {
        v[s[i]]++;
    }
    long long ans = 0;
    for (int i = 1; i < v.size(); i++){
        ans += (long long)v[i]*(long long)v[i];
    }
    cout << ans << endl;
}