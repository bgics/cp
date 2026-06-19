#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<int>& coins, vector<int>& solution) {
  int max_sum = 0;
  for (auto coin : coins) {
    max_sum += coin;
  }

  vector<vector<bool>> possible(max_sum + 1,
                                vector<bool>(coins.size() + 1, false));

  possible[0] = vector<bool>(coins.size() + 1, true);

  for (int sum = 1; sum <= max_sum; sum++) {
    for (size_t k = 1; k <= coins.size(); k++) {
      if (sum >= coins[k - 1]) {
        possible[sum][k] =
            possible[sum - coins[k - 1]][k - 1] || possible[sum][k - 1];
      } else {
        possible[sum][k] = possible[sum][k - 1];
      }
    }
  }

  for (int i = 1; i <= max_sum; i++) {
    if (possible[i][coins.size()]) {
      solution.push_back(i);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> coins(n);
  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }

  vector<int> solution;

  solve(coins, solution);

  cout << solution.size() << "\n";
  for (auto value : solution) {
    cout << value << " ";
  }
}
