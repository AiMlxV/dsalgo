#include "bits/stdc++.h"
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

void combi(size_t n, vector<size_t> &sol, size_t len, size_t nest1) {
  if (len == n) {
    int s = 0;
    for (int x : sol) {
        s += x;
    }
    if (s >= nest1) {
        for (int x : sol) {
            cout << x;
        }
        cout << "\n";
    }
    return;
  }

  sol[len] = 0;
  combi(n, sol, len + 1, nest1);
  sol[len] = 1;
  combi(n, sol, len + 1, nest1);
}

int main() {
  size_t a, b;
  cin >> a >> b;
  vector<size_t> ans_set(a);
  combi(a, ans_set, 0, b);
}