#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool possible(ll total_time, vector<ll>& times, ll t) {
  ll sum = 0;
  for (auto time : times) {
    sum += total_time / time;
    if (sum >= t) return true;
  }

  return sum >= t;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, t;
  cin >> n >> t;

  vector<ll> times;
  for (int i = 0; i < n; i++) {
    ll time;
    cin >> time;
    times.push_back(time);
  }

  sort(times.begin(), times.end());

  ll e = times.back() * t;
  ll ans = e;
  ll s = 0;

  while (s <= e) {
    ll mid = s + ((e - s) / 2);

    if (possible(mid, times, t)) {
      ans = mid;
      e = mid - 1;
    } else {
      s = mid + 1;
    }
  }

  cout << ans;
}
