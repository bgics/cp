#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct project {
  int start;
  int end;
  ll reward;

  bool operator<(const project& other) const { return end < other.end; }
  bool operator<(const int& other) const { return end < other; }
};

ll solve(vector<project>& projects) {
  vector<ll> dp(projects.size());

  dp[0] = projects[0].reward;

  for (size_t i = 1; i < projects.size(); i++) {
    auto end = projects.begin() + i;
    auto it = lower_bound(projects.begin(), end, projects[i].start);

    if (it == projects.begin()) {
      dp[i] = max(projects[i].reward, dp[i - 1]);
    } else {
      --it;
      dp[i] = max(dp[i - 1], projects[i].reward + dp[it - projects.begin()]);
    }
  }

  return dp.back();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<project> projects(n);

  for (auto& project : projects) {
    cin >> project.start;
    cin >> project.end;
    cin >> project.reward;
  }

  sort(projects.begin(), projects.end());

  cout << solve(projects);
}
