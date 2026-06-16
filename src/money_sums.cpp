#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> coins(n);
  set<int> sums;

  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }

  for (auto coin : coins) {
    set<int> new_sums;
    new_sums.insert(coin);
    for (auto sum : sums) {
      new_sums.insert(sum + coin);
    }
    sums.merge(new_sums);
  }

  cout << sums.size() << "\n";
  for (auto sum : sums) {
    cout << sum << " ";
  }
}
