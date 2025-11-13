#include "bits/stdc++.h"
#include <map>
#include <vector>

using namespace std;

long long getGF(long long person, const map<long long, long long> &father){
    //first check father
    auto fatherIt = father.find(person);
    if (fatherIt == father.end()) {
        //this mean there is no father specifice
        return 0;
    }
    //now let check grandfather from father
    auto grandIt = father.find(fatherIt->second);
    if (grandIt == father.end()) {
        //this mean there is no grandfather specifice
        return 0;
    }
    // now let return grandfather
    return grandIt->second;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  map<long long, vector<long long>> child;
  map<long long, long long> father;
  int n,m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    long long F, S;
    cin >> F >> S;
    child[F].push_back(S);
    father[S] = F;
  }

  for (int i = 0; i < m; i++) {
    long long n1, n2;
    cin >> n1 >> n2;

    //same hito
    if (n1 == n2) {
        cout << "NO\n";
        continue;
    }

    //different hito but relative? let find by
    auto gf1 = getGF(n1,father);
    auto gf2 = getGF(n2,father);
    
    if ((gf1 != 0 and gf2 != 0) and gf1 == gf2) {
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
  }
  return 0;
}