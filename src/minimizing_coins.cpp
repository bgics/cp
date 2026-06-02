#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int solve(int x, vector<int>& coins) {
  vector<int> dp(x + 1);

  dp[0] = 0;

  for (int i = 1; i <= x; i++) {
    dp[i] = 1e7;
    for (auto coin : coins) {
      if (i >= coin) {
        dp[i] = min(dp[i], dp[i - coin] + 1);
      }
    }
  }

  if (dp[x] == 1e7) {
    return -1;
  } else {
    return dp[x];
  }
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
