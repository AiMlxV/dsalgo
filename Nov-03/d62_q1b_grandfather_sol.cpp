#include "bits/stdc++.h"

using namespace std;

long long getGrandfather(long long person,const map<long long, long long> &parent) {
  auto fatherIt = parent.find(person);
  if (fatherIt == parent.end()) {
    return 0;
  }
  auto grandIt = parent.find(fatherIt->second);
  if (grandIt == parent.end()) {
    return 0;
  }
  return grandIt->second;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  if (!(cin >> N >> M)) {
    return 0;
  }

  map<long long, vector<long long>> children;
  map<long long, long long> parent;

  for (int i = 0; i < N; ++i) {
    long long F, S;
    cin >> F >> S;
    children[F].push_back(S);
    parent[S] = F;
  }

  for (int i = 0; i < M; ++i) {
    long long A, B;
    cin >> A >> B;

    if (A == B) {
      cout << "NO\n";
      continue;
    }

    long long g1 = getGrandfather(A, parent);
    long long g2 = getGrandfather(B, parent);

    if (g1 != 0 && g1 == g2) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}