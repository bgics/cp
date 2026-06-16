#include <bits/stdc++.h>
using namespace std;

#define ll long long

int solve(int a, int b) {
  vector<vector<int>> dp(a + 1, vector<int>(b + 1, (INT_MAX / 2) - 1));

  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      if (i == j) {
        dp[i][j] = 0;
        continue;
      }
      for (int cut = 1; cut < i; cut++) {
        dp[i][j] = min(dp[i][j], 1 + dp[cut][j] + dp[i - cut][j]);
      }
      for (int cut = 1; cut < j; cut++) {
        dp[i][j] = min(dp[i][j], 1 + dp[i][cut] + dp[i][j - cut]);
      }
    }
  }

  return dp[a][b];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b;
  cin >> a >> b;

  cout << solve(a, b);
}
