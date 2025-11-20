#include "bits/stdc++.h"
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

void combi(size_t n, vector<size_t> &sol, size_t len, size_t nof1) {
  if (len == n) {
    int s = 0;
    for (int x : sol) {
        s += x;
    }
    if (s == nof1) {
        for (int x : sol) {
            cout << x;
        }
        cout << "\n";
    }
    return;
  }

  sol[len] = 0;
  combi(n, sol, len + 1, nof1);
  sol[len] = 1;
  combi(n, sol, len + 1, nof1);
}

int main() {
  size_t a, b;
  cin >> a >> b;
  vector<size_t> ans_set(b);
  combi(b, ans_set, 0, a);
}