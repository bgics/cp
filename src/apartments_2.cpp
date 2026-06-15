#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  ll k;
  cin >> n >> m >> k;

  multiset<ll> applicants;
  multiset<ll> apartments;

  for (int i = 0; i < n; i++) {
    ll applicant;
    cin >> applicant;
    applicants.insert(applicant);
  }

  for (int i = 0; i < m; i++) {
    ll apartment;
    cin >> apartment;
    apartments.insert(apartment);
  }

  int ans = 0;

  for (auto applicant : applicants) {
    auto it = apartments.lower_bound(applicant - k);

    if (it != apartments.end() && *it <= applicant + k) {
      ans++;
      apartments.erase(it);
    }
  }

  cout << ans;
}
