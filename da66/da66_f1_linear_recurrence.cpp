#include "bits/stdc++.h"
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

long lrecur(int n, int k, vector<int> &c, vector<int> &a, vector<int> &memo) {
  if (n < k) {
    return a[n] % 32717;
  }

  if (memo[n] != -1) {
    return memo[n];
  }

  int sum = 0;
  for (int m = 1; m <= k; m++) {

    int term = (c[m] * lrecur(n - m, k, c, a,memo)) % 32717;
    sum = (sum + term) % 32717;
  }
  return memo[n] = sum;
}

int main() {
  int k, n;
  cin >> k >> n;

  vector<int> c_1tok(k + 1);
  vector<int> a_0tok_1(k);

  for (int i = 1; i <= k; i++) {
    cin >> c_1tok[i];
  }
  for (int i = 0; i < k; i++) {
    cin >> a_0tok_1[i];
  }

  vector<int> memo(n+1);
  fill(memo.begin(),memo.end(),-1);
  cout << lrecur(n, k, c_1tok, a_0tok_1,memo) << endl;
}