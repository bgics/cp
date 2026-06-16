#include <bits/stdc++.h>
using namespace std;

#define ll long long

int solve(vector<int>& array) {
  vector<int> tails;

  for (auto value : array) {
    auto it = lower_bound(tails.begin(), tails.end(), value);

    if (it == tails.end()) {
      tails.push_back(value);
    } else {
      *it = value;
    }
  }

  return tails.size();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> array(n);

  for (int i = 0; i < n; i++) {
    cin >> array[i];
  }

  cout << solve(array);
}
