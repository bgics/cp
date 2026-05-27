#include <iostream>
#include <set>
using namespace std;

#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  set<int> arr;
  for (int i = 0; i < n; i++) {
    arr.insert(i + 1);
  }

  int mod_k = k;
  if (k > n) {
    mod_k = k % n;
  }

  auto it = arr.begin();
  for (int i = 0; i < mod_k; i++) {
    if (++it == arr.end()) {
      it = arr.begin();
    }
  }

  while (!arr.empty()) {
    if (arr.size() == 1) {
      cout << *arr.begin();
      break;
    }

    cout << *it << " ";
    it = arr.erase(it);
    if (it == arr.end()) it = arr.begin();

    if (k > arr.size()) {
      mod_k = k % arr.size();
    }

    for (int i = 0; i < mod_k; i++) {
      if (++it == arr.end()) {
        it = arr.begin();
      }
    }
  }
}
