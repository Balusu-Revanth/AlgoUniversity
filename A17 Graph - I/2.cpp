#include <bits/stdc++.h>
using namespace std;

void bfs(string start, unordered_map<string, vector<pair<string, string>>>& g, unordered_set<string>& visited, unordered_map<string, string>& parent, unordered_map<string, string>& road) {
  queue<string> q;
  q.push(start);
  visited.insert(start);
  while (!q.empty()) {
    string node = q.front();
    q.pop();
    for (auto child: g[node]) {
      if (visited.find(child.first) == visited.end()) {
        q.push(child.first);
        visited.insert(child.first);
        parent[child.first] = node;
        road[child.first] = child.second;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  unordered_map<string, vector<pair<string, string>>> g;
  unordered_set<string> visited;
  unordered_map<string, string> parent;
  unordered_map<string, string> road;
  for (int i = 0; i < m; i++) {
    string u, v, l;
    cin >> u >> v >> l;
    g[u].push_back(make_pair(v, l));
  }
  string s, t;
  cin >> s >> t;
  bfs(s,g,visited,parent,road);
  if (visited.find(t) == visited.end()) {
    cout << "Impossible" << "\n";
  }
  else {
    vector<string> ans;
    while (t != s) {
      ans.push_back(road[t]);
      t = parent[t]; 
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << "\n";
    }
  }
}