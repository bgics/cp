#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

int solve(int height) {
  vector<pair<ll, ll>> dp(height + 1);

  dp[1] = pair(1, 1);

  for (int i = 2; i <= height; i++) {
    // The floor below this one can either be block block or one long block
    ll new_bb = ((4 * dp[i - 1].first) + dp[i - 1].second) % MOD;
    ll new_b = (dp[i - 1].first + (2 * dp[i - 1].second)) % MOD;

    dp[i] = pair(new_bb, new_b);
  }

  return (dp[height].first + dp[height].second) % MOD;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int height;
    cin >> height;

    cout << solve(height) << "\n";
  }
}
