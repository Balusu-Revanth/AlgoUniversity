#include <bits/stdc++.h>
using namespace std;

int dfs(int node, int parent, vector<vector<int>>& g, vector<int>& gain, vector<int>& ans) {
  int sum = gain[node];
  for (int child: g[node]) {
    if (child != parent) {
      sum += dfs(child, node, g, gain, ans);
    }
  }
  return ans[node] = sum;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  if (n == 1) {
    int ans;
    cin >> ans;
    cout << ans;
    exit(0);
  }
  vector<vector<int>> g(n+1);
  for (int v2 = 2; v2 <= n; v2++) {
    int v1;
    cin >> v1;
    g[v1].push_back(v2);
  }
  vector<int> gain(n+1), ans(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> gain[i];
  }
  dfs(1, -1, g, gain, ans);
  int maxg = INT_MIN;
  for (int i = 1; i <= n; i++) {
    if (maxg < ans[i]) {
      maxg = ans[i];
    }
  }
  cout << maxg;
}