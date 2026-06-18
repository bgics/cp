#include <bits/stdc++.h>
using namespace std;

#define ll long long

int solve(vector<int>& array1, vector<int>& array2, vector<int>& solution) {
  vector<vector<int>> dp(array1.size(), vector<int>(array2.size()));

  for (size_t i = 0; i < array1.size(); i++) {
    for (size_t j = 0; j < array2.size(); j++) {
      if (array1[i] == array2[j]) {
        if (i == 0 || j == 0) {
          dp[i][j] = 1;
        } else {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        }
      } else {
        int left = 0;
        if (i != 0) {
          left = dp[i - 1][j];
        }
        int right = 0;
        if (j != 0) {
          right = dp[i][j - 1];
        }

        dp[i][j] = max(left, right);
      }
    }
  }

  int i = array1.size() - 1, j = array2.size() - 1;
  while (i >= 0 && j >= 0) {
    if (array1[i] == array2[j]) {
      solution.push_back(array1[i]);
      i--;
      j--;
    } else {
      if (i == 0) {
        j--;
      } else if (j == 0) {
        i--;
      } else if (dp[i][j - 1] >= dp[i - 1][j]) {
        j--;
      } else {
        i--;
      }
    }
  }

  reverse(solution.begin(), solution.end());

  return dp.back().back();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<int> array1(n), array2(m), solution;

  for (auto& value : array1) {
    cin >> value;
  }

  for (auto& value : array2) {
    cin >> value;
  }

  cout << solve(array1, array2, solution) << "\n";

  for (auto value : solution) {
    cout << value << " ";
  }
}
