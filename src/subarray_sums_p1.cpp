#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  ll x;
  cin >> n >> x;

  vector<ll> arr;
  for (int i = 0; i < n; i++) {
    ll value;
    cin >> value;
    arr.push_back(value);
  }

  vector<ll> acc;
  ll sum = 0;
  for (auto value : arr) {
    sum += value;
    acc.push_back(sum);
  }

  int ans = 0;
  for (auto it = acc.begin(); it != acc.end(); ++it) {
    if (*it == x) {
      ++ans;
      continue;
    }

    if (it == acc.begin() || *it < x) {
      continue;
    }

    if (binary_search(acc.begin(), it, (*it) - x)) ++ans;
  }

  cout << ans;
}
