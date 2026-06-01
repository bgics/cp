#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define MOD 1000000007

int solve(int x) {
  vector<int> dp(x + 1);

  dp[0] = 1;

  for (int i = 1; i <= x; i++) {
    dp[i] = 0;
    for (int j = 1; j <= 6 && j <= i; j++) {
      dp[i] += (dp[i - j]);
      dp[i] %= MOD;
    }
  }

  return dp[x];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  cout << solve(n);
}
