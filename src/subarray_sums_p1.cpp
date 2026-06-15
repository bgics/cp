#include <bits/stdc++.h>
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

  int i = 0, j = 0;
  ll sum = arr[0];

  int ans = 0;
  while (j < n) {
    if (sum < x) {
      if (j == n - 1) break;
      sum += arr[++j];
    } else if (sum > x) {
      sum -= arr[i++];
    } else {
      ++ans;
      sum -= arr[i++];
    }
  }

  cout << ans;
}
