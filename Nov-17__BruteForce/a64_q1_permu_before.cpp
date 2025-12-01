#include <cstddef>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void permu(int n, int len, string ans, bool used[], map<int, vector<int>> &correct_order) {
  if (len == n) {
    cout << ans << "\n";
    return;
  }
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      bool can_place = true;
      if (correct_order.count(i)) {
        for (int before : correct_order[i]) {
          if (!used[before]) {
            can_place = false;
            break;
          }
        }
      }
      if (!can_place)
        continue;

      used[i] = true;
      permu(n, len + 1, ans + to_string(i) + " ", used, correct_order);
      used[i] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int m, n;
  cin >> n >> m;
  map<int, vector<int>> correct_order;
  bool used[n];
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    correct_order[b].push_back(a);
  }

  permu(n, 0, "", used, correct_order);
}
