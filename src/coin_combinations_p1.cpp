#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

int solve(int x, vector<int>& coins) {
  vector<int> dp(x + 1);

  dp[0] = 1;

  for (int i = 1; i <= x; i++) {
    dp[i] = 0;
    for (auto coin : coins) {
      if (i >= coin) {
        dp[i] += dp[i - coin];
        dp[i] %= MOD;
      }
    }
  }

  return dp[x];
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
