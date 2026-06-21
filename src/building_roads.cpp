#include <bits/stdc++.h>
using namespace std;

#define ll long long

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
  if (visited[node]) return;

  visited[node] = true;
  for (auto neighbour : adj[node]) {
    dfs(neighbour, adj, visited);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1, vector<int>());

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<bool> visited(n + 1, false);
  vector<int> unconnected;
  for (int node = 1; node <= n; node++) {
    if (visited[node]) continue;
    unconnected.push_back(node);
    dfs(node, adj, visited);
  }

  cout << unconnected.size() - 1 << "\n";
  for (size_t i = 0; i < unconnected.size() - 1; i++) {
    cout << unconnected[i] << " " << unconnected[i + 1] << "\n";
  }
}
