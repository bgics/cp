#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x, n;

  cin >> x >> n;

  set<int> light_positions = {0, x};
  multiset<int> gaps = {x};

  int p;
  while (cin >> p) {
    auto right = light_positions.upper_bound(p);
    auto left = right;
    --left;

    gaps.erase(gaps.find(*right - *left));
    gaps.insert(p - *left);
    gaps.insert(*right - p);

    light_positions.insert(p);

    auto ans = gaps.end();
    --ans;
    cout << *ans << " ";
  }
}
