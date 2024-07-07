#include <bits/stdc++.h>
using namespace std;

vector<bool> bfs(int start, vector<vector<int>>& g) {
  int n = g.size();
  queue<int> q;
  vector<bool> visited(n, false);
  q.push(start);
  visited[start] = true;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (int child: g[node]) {
      if (!visited[child]) {
        q.push(child);
        visited[child] = true;
      }
    }
  }
  return visited;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int x, y, n;
    cin >> x >> y >> n;
    vector<int> cx(n), cy(n), r(n);
    for (int i = 0; i < n; i++) {
      cin >> cx[i] >> cy[i] >> r[i];
    }
    vector<vector<int>> g(n+2);
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        double dist = sqrt(pow((cx[i]-cx[j]),2)+pow((cy[i]-cy[j]),2));
        if (dist <= r[i]+r[j]) {
          g[i].push_back(j);
          g[j].push_back(i);
        }
      }
      if (cx[i] <= r[i] || cy[i] <= r[i]) {
        g[i].push_back(n);
        g[n].push_back(i);
      }
      if (x-cx[i] <= r[i] || y-cy[i] <= r[i]) {
        g[i].push_back(n+1);
        g[n+1].push_back(i);
      }
    }
    vector<bool> visited = bfs(n,g);
    visited[n+1] ? cout << "NO\n" : cout << "YES\n";
  }
}