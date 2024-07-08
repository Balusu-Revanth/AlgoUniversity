#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>>& g, vector<int>& vis, vector<int>& dfsvis) {
  vis[node] = 1;
  dfsvis[node] = 1;
  for (int child: g[node]) {
    if (!vis[child] && dfs(child, g, vis, dfsvis)) return true;
    else if (dfsvis[child]) return true;
  }
  dfsvis[node] = 0;
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  if (n == 1) {
    cout << "YES";
    return 0;
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }
  vector<int> vis(n, 0), dfsvis(n, 0);
  for (int i = 0; i < n; i++) {
    if (!vis[i] && dfs(i, g, vis, dfsvis)) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}