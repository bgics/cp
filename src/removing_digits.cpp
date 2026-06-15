#include <bits/stdc++.h>

#include <climits>
using namespace std;

#define ll long long

int solve(int n) {
  vector<int> dp(n + 1, INT_MAX - 1);

  dp[0] = 0;

  for (int i = 1; i <= n; i++) {
    int current_number = i;
    while (current_number > 0) {
      int digit = current_number % 10;
      current_number /= 10;

      if (i >= digit) {
        dp[i] = min(dp[i], dp[i - digit] + 1);
      }
    }
  }

  return dp[n];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  cout << solve(n);
}
