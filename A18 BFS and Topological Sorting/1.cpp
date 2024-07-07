#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int start, vector<vector<int>> g) {
  int n = g.size();
  queue<int> q;
  vector<bool> visited(n+1, false);
  vector<int> dist(n+1);
  q.push(start);
  visited[start] = true;
  dist[start] = 0;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (auto child: g[node]) {
      if (!visited[child]) {
        q.push(child);
        visited[child] = true;
        dist[child] = dist[node]+1;
      }
    }
  }
  return dist;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int c1, c2, c3, n, m;
  cin >> c1 >> c2 >> c3 >> n >> m;
  vector<vector<int>> g(n+1);
  for (int i = 0; i < m; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    g[v1].push_back(v2);
    g[v2].push_back(v1);
  }
  vector<int> dist1 = bfs(1,g);
  vector<int> dist2 = bfs(2,g);
  vector<int> distn = bfs(n,g);
  int ans = INT_MAX;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, c1*dist1[i] + c2*dist2[i] + c3*distn[i]);
  }
  cout << ans;
}