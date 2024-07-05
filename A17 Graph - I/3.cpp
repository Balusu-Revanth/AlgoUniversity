#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int start, vector<vector<int>>& g) {
  int n = g.size();
  queue<int> q;
  vector<bool> visited(n, false);
  vector<int> dist(n);
  q.push(start);
  visited[start] = true;
  dist[start] = 0;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (int child: g[node]) {
      if (!visited[child]) {
        q.push(child);
        visited[child] = true;
        dist[child] = dist[node] + 1;
      }
    }
  }
  return dist;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n+1);
  for (int i = 0; i < m; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    g[v1].push_back(v2);
    g[v2].push_back(v1);
  }
  int src, dest;
  cin >> src >> dest;
  vector<int> dist = bfs(src,g);
  cout << dist[dest];
}