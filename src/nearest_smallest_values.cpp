#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
    arr.push_back(value);
  }

  stack<int> s;

  for (int i = 0; i < n; i++) {
    while (!s.empty() && (arr[s.top()] >= arr[i])) s.pop();

    if (s.empty()) {
      cout << 0 << " ";
    } else {
      cout << s.top() + 1 << " ";
    }

    s.push(i);
  }
}
