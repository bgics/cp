#include <bits/stdc++.h>
using namespace std;

#define ll long long

void dfs(int i, vector<vector<int>>& adj, vector<bool>& visited) {
  if (visited[i]) return;
  visited[i] = true;
  for (auto n : adj[i]) {
    dfs(n, adj, visited);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> floor_map(n, vector<int>(m, 0));

  int nodes = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      if (c == '.') {
        floor_map[i][j] = ++nodes;
      }
    }
  }

  vector<vector<int>> adj(nodes + 1, vector<int>());

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (floor_map[i][j] != 0) {
        if (j > 0 && floor_map[i][j - 1] != 0) {
          adj[floor_map[i][j]].push_back(floor_map[i][j - 1]);
        }
        if (j < m - 1 && floor_map[i][j + 1] != 0) {
          adj[floor_map[i][j]].push_back(floor_map[i][j + 1]);
        }
        if (i > 0 && floor_map[i - 1][j] != 0) {
          adj[floor_map[i][j]].push_back(floor_map[i - 1][j]);
        }
        if (i < n - 1 && floor_map[i + 1][j] != 0) {
          adj[floor_map[i][j]].push_back(floor_map[i + 1][j]);
        }
      }
    }
  }

  int answer = 0;
  vector<bool> visited(nodes + 1, false);

  for (int i = 1; i <= nodes; i++) {
    if (visited[i]) continue;
    dfs(i, adj, visited);
    answer++;
  }

  cout << answer;
}
