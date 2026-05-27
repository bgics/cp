#include <vector>
using namespace std;

void recursive(vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2,
               int& count, int r, int n) {
  if (r == n) {
    count++;
    return;
  } else {
    for (int c = 0; c < n; c++) {
      if (cols[c] || diag1[r + c] || diag2[c + n - r - 1]) continue;
      cols[c] = diag1[r + c] = diag2[c + n - r - 1] = true;
      recursive(cols, diag1, diag2, count, r + 1, n);
      cols[c] = diag1[r + c] = diag2[c + n - r - 1] = false;
    }
  }
}

int search(int n) {
  vector<bool> diag1(n * 2 - 1, false);
  vector<bool> diag2(n * 2 - 1, false);
  vector<bool> cols(n, false);

  int count = 0;

  recursive(cols, diag1, diag2, count, 0, n);
  return count;
}

int main() {
  int n;
  cin >> n;

  cout << search(n) << "\n";
}
