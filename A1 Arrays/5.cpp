#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n;
    cin >> n;
    vector<long long int> psum;
    long long int sum = 0;
    psum.push_back(sum);
    for (long long int i = 0; i < n; i++) {
        long long int x;
        cin >> x;
        sum += x;
        psum.push_back(sum);
    }
    long long int q;
    cin >> q;
    while (q--) {
        long long int l, r;
        cin >> l >> r;
        cout << psum[r] - psum[l-1] << "\n";
    }
}