#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> arr;
  int value;
  while (cin >> value) {
    arr.push_back(value);
  }

  sort(arr.begin(), arr.end());

  int missing = n;
  for (int i = 0; i < arr.size(); i++) {
    if (i + 1 != arr[i]) {
      missing = i + 1;
      break;
    }
  }

  cout << missing << "\n";
}
