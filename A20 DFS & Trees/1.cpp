#include <bits/stdc++.h>
using namespace std;

int dfs(int node, int parent, vector<vector<int>>& g, vector<int>& ans) {
  int sum = 1;
  for (int child: g[node]) {
    if (child != parent) {
      sum += dfs(child, node, g, ans);
    }
  }
  return ans[node] = sum;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<vector<int>> g(n+1);
  for (int v2 = 2; v2 <= n; v2++) {
    int v1;
    cin >> v1;
    g[v1].push_back(v2);
  }
  vector<int> ans(n+1);
  dfs(1,-1,g,ans);
  for (int i = 1; i <= n; i++) {
    cout << ans[i]-1 << " ";
  }
}