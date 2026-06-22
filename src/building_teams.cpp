#include <bits/stdc++.h>
using namespace std;

#define ll long long

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
  vector<int> group(n + 1, -1);

  bool impossible = false;

  for (int i = 1; i <= n; i++) {
    if (visited[i]) continue;
    visited[i] = true;

    queue<int> q;
    q.push(i);

    group[i] = 1;

    while (!q.empty()) {
      int current = q.front();
      q.pop();

      for (auto neighbour : adj[current]) {
        if (visited[neighbour]) {
          if (group[current] == group[neighbour]) {
            impossible = true;
            break;
          }
          continue;
        };
        visited[neighbour] = true;
        group[neighbour] = group[current] == 1 ? 2 : 1;
        q.push(neighbour);
      }

      if (impossible) break;
    }

    if (impossible) break;
  }

  if (impossible) {
    cout << "IMPOSSIBLE\n";
  } else {
    for (int i = 1; i <= n; i++) {
      cout << group[i] << " ";
    }
    cout << "\n";
  }
}
