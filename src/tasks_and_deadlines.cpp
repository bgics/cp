#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<pair<int, int>> tasks;
  for (int i = 0; i < n; i++) {
    int a, d;
    cin >> a >> d;
    tasks.push_back(make_pair(a, d));
  }

  sort(tasks.begin(), tasks.end());

  ll time = 0;
  ll reward = 0;

  for (auto task : tasks) {
    time += (ll)task.first;
    reward += task.second - time;
  }

  cout << reward;
}
