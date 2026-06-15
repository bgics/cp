#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;

  vector<int> a;
  while (n--) {
    int val;
    cin >> val;
    a.push_back(val);
  }

  vector<int> b;
  while (m--) {
    int val;
    cin >> val;
    b.push_back(val);
  }

  sort(b.begin(), b.end());
  sort(a.begin(), a.end());

  int ans = 0;

  int i = 0, j = 0;
  int a_len = a.size();
  int b_len = b.size();

  while (i < a_len && j < b_len) {
    if (a[i] - k <= b[j] && b[j] <= a[i] + k) {
      ans++;
      i++;
      j++;
    }

    if (b[j] > a[i] + k) {
      i++;
    }

    if (b[j] < a[i] - k) {
      j++;
    }
  }

  cout << ans << "\n";
}
