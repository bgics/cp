#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  set<int> arr;
  for (int i = 0; i < n; i++) {
    arr.insert(i + 1);
  }

  if (n == 1) {
    cout << *arr.begin();
    return 0;
  }

  auto it = ++arr.begin();

  while (!arr.empty()) {
    if (arr.size() <= 2) {
      cout << *it << " ";
      arr.erase(it);
      cout << *arr.begin();
      break;
    }

    auto next = it;
    ++next;

    if (next == arr.end()) {
      next = arr.begin();
      ++next;
    } else {
      ++next;

      if (next == arr.end()) {
        next = arr.begin();
      }
    }

    cout << *it << " ";
    arr.erase(it);
    it = next;
  }
}
