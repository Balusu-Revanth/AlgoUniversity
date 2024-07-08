#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int level, vector<vector<int>>& g, vector<int>& dist) {
  for (int child: g[node]) {
    if (child != parent) {
      dfs(child, node, level+1, g, dist);
    }
  }
  dist[node] = level;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int n;
  cin >> n;
  if (n <= 1) {
    cout << "0";
    exit(0);
  }
  vector<vector<int>> g(n+1);
  for (int i = 0; i < n-1; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    g[v1].push_back(v2);
    g[v2].push_back(v1);
  }
  vector<int> dist1(n+1);
  dfs(1,-1,0,g,dist1);
  int fnode1, maxd = 0;
  for (int i = 1; i <= n; i++) {
    if (dist1[i] > maxd) {
      maxd = dist1[i];
      fnode1 = i;
    }
  }
  vector<int> dist2(n+1);
  dfs(fnode1,-1,0,g,dist2);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (dist2[i] > ans) {
      ans = dist2[i];
    }
  }
  cout << ans;
}