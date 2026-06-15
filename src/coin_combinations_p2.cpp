#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

int solve(int x, vector<int>& coins) {
  vector<int> dp(x + 1);
  vector<set<multiset<int>>> solutions(x + 1);

  dp[0] = 1;
  solutions[0] = set<multiset<int>>();
  solutions[0].insert(multiset<int>({}));

  for (int i = 1; i <= x; i++) {
    dp[i] = 0;
    solutions[i] = set<multiset<int>>();
    for (auto coin : coins) {
      if (i >= coin) {
        dp[i] += dp[i - coin];
        dp[i] %= MOD;

        for (auto solution : solutions[i - coin]) {
          solution.insert(coin);
          solutions[i].insert(solution);
        }
      }
    }
  }

  // for (auto solution : solutions[x]) {
  //   for (auto coin : solution) {
  //     cout << coin << " ";
  //   }
  //   cout << "\n";
  // }
  return solutions[x].size();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, x;
  cin >> n >> x;

  vector<int> coins(n);

  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }

  cout << solve(x, coins);
}
