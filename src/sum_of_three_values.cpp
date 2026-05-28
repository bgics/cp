#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, x;
  cin >> n >> x;

  vector<pair<int, int>> arr;
  for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
    arr.push_back(make_pair(value, i));
  }

  sort(arr.begin(), arr.end());

  for (int i = 0; i < n - 1; i++) {
    int s = i + 1;
    int e = n - 1;

    while (s < e) {
      if (arr[i].first + arr[s].first + arr[e].first < x) {
        s += 1;
      } else if (arr[i].first + arr[s].first + arr[e].first > x) {
        e -= 1;
      } else {
        cout << arr[i].second + 1 << " " << arr[s].second + 1 << " "
             << arr[e].second + 1;
        return 0;
      }
    }
  }

  cout << "IMPOSSIBLE";
}
