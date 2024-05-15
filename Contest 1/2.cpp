#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while (q--) {
        long long n;
        cin >> n;
        cout << ceil(log(n)/log(2)) << endl;
    }
}