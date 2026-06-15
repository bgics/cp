#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<pair<pair<int, int>, int>> customers;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    customers.push_back(make_pair(make_pair(a, b), i));
  }

  sort(customers.begin(), customers.end());

  int max_rooms = 1;
  vector<pair<int, int>> ans;
  ans.push_back(make_pair(customers[0].second, max_rooms));

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      occupied;
  occupied.push(make_pair(customers[0].first.second, max_rooms));

  for (auto customer = ++customers.begin(); customer != customers.end();
       ++customer) {
    if (customer->first.first > occupied.top().first) {
      int vacant_room = occupied.top().second;
      occupied.pop();
      occupied.push(make_pair(customer->first.second, vacant_room));
      ans.push_back(make_pair(customer->second, vacant_room));
    } else {
      occupied.push(make_pair(customer->first.second, ++max_rooms));
      ans.push_back(make_pair(customer->second, max_rooms));
    }
  }

  sort(ans.begin(), ans.end());

  cout << max_rooms << "\n";
  for (auto room : ans) {
    cout << room.second << " ";
  }
}
