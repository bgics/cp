#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  set<int> s;
  while (n--) {
    int num;
    cin >> num;

    s.insert(num);
  }

  cout << s.size() << "\n";

  return 0;
}
