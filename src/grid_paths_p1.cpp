#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

int calculate_left_position(int pos, int n) {
  int col = pos % n;
  int row = pos / n;

  if (col == 0) {
    return -1;
  } else {
    return (row * n) + (col - 1);
  }
}

int calculate_up_position(int pos, int n) {
  int col = pos % n;
  int row = pos / n;

  if (row == 0) {
    return -1;
  } else {
    return ((row - 1) * n) + col;
  }
}

int solve(int n, vector<bool>& grid) {
  vector<int> dp(n * n, 0);

  if (!grid[0]) {
    dp[0] = 1;
  }

  for (int i = 1; i < n * n; i++) {
    if (grid[i]) continue;

    int left_position = calculate_left_position(i, n);
    int up_position = calculate_up_position(i, n);

    if (left_position >= 0) {
      dp[i] += dp[left_position];
      dp[i] %= MOD;
    }

    if (up_position >= 0) {
      dp[i] += dp[up_position];
      dp[i] %= MOD;
    }
  }

  return dp.back();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<bool> grid(n * n, false);

  for (int i = 0; i < n * n; i++) {
    char c;
    cin >> c;
    if (c == '*') {
      grid[i] = true;
    }
  }

  cout << solve(n, grid);
}
