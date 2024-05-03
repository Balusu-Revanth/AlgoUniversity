#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int n, w;
    cin >> n >> w;
    if (n < 3) {
        cout << -1;
        exit(0);
    }
    vector<pair<long int, long int>> prs;
    for (long int i = 0; i < n; i++) {
        long int x;
        cin >> x;
        prs.push_back(make_pair(x, i+1));
    }
    sort(prs.begin(), prs.end());
    for (long int i = 0; i < n-1; i++) {
        long int req = w - prs[i].first;
        if (req < 0) {
            break;
        }
        long int l = i+1, r = n-1;
        while (l < r) {
            long long int sum = prs[l].first + prs[r].first;
            if (sum < req) {
                l++;
            }
            else if (sum > req) {
                r--;
            }
            else {
                cout << prs[i].second << " " << prs[l].second << " " << prs[r].second;
                exit(0);
            }
        }
        while(i < n-1 && prs[i].first == prs[i+1].first) i++;
    }
    cout << -1;
    exit(0);
}