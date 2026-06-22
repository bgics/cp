#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9

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

  vector<int> previous(n + 1, -1);
  vector<bool> visited(n + 1, false);
  vector<int> distance(n + 1, INF);

  priority_queue<pair<int, int>> q;

  distance[1] = 0;
  q.push({0, 1});

  while (!q.empty()) {
    int top = q.top().second;
    q.pop();

    if (visited[top]) continue;
    visited[top] = true;

    for (auto neighbour : adj[top]) {
      if (distance[top] + 1 < distance[neighbour]) {
        distance[neighbour] = distance[top] + 1;
        previous[neighbour] = top;
        q.push({-distance[neighbour], neighbour});
      }
    }
  }

  vector<int> answer;
  if (distance[n] != INF) {
    cout << distance[n] + 1 << "\n";
    int current = n;
    while (current != 1) {
      answer.push_back(current);
      current = previous[current];
    }
    answer.push_back(current);
    reverse(answer.begin(), answer.end());
    for (auto node : answer) {
      cout << node << " ";
    }
    cout << "\n";
  } else {
    cout << "IMPOSSIBLE\n";
  }
}
