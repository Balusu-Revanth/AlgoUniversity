#include <bits/stdc++.h>
using namespace std;

void toposort(vector<int> indeg, vector<vector<int>>& g) {
  int n = g.size();
  queue<int> q;
  vector<bool> visited(n, false);
  for (int i = 0; i < n; i++) {
    if (indeg[i] == 0) {
      q.push(i);
      visited[i] = true;
      cout << i << " ";
    }
  }
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (int child: g[node]) {
      if (!visited[child]) {
        indeg[child]--;
        if (indeg[child] == 0) {
          q.push(child);
          visited[child] = true;
          cout << child << " ";
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  if (n == 0) return 0;
  vector<vector<int>> g(n);
  vector<int> indeg(n, 0);
  for (int i = 0; i < m; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    g[v1].push_back(v2);
    indeg[v2]++;
  }
  toposort(indeg,g);
}