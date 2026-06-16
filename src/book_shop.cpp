#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct book {
  int price;
  int pages;
};

int solve(int x, vector<book>& books) {
  vector<int> dp(x + 1, 0);

  for (auto& book : books) {
    for (int i = x; i >= book.price; i--) {
      dp[i] = max(dp[i], dp[i - book.price] + book.pages);
    }
  }

  return dp[x];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, x;
  cin >> n >> x;
  vector<book> books(n);

  for (int i = 0; i < n; i++) {
    cin >> books[i].price;
  }

  for (int i = 0; i < n; i++) {
    cin >> books[i].pages;
  }

  cout << solve(x, books);
}
