#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;
int cnt = 0;
set<string> ans_set;
void permu(int current, int n, string msg, string cur_msg, vector<bool> &used) {
  if (current == n) {
    ans_set.insert(cur_msg);
    cout << cur_msg << endl;
    cnt++;
  } else {
    // bool seen_at_this_level[256] = {false};
    for (int i = 0; i < n; i++) {

      if (used[i]) {
        continue;
      }

    //   if (seen_at_this_level[msg[i]]) {
    //     continue;
    //   }

    //   seen_at_this_level[msg[i]] = true;

      used[i] = true;
      permu(current + 1, n, msg, cur_msg + msg[i], used);
      used[i] = false;
    }
  }
}

int main() {
  int n;
  string msg;
  cin >> n;
  cin >> msg;
  vector<char> sol(n);
  vector<bool> used(msg.length(), false);
  sort(msg.begin(),msg.end());
  permu(0, n, msg, "", used);

  cout << cnt << endl;
  cout << ans_set.size() << endl;
}