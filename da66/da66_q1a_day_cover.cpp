#include "bits/stdc++.h"
using namespace std;
int n,m;
int total = INT_MAX;
int day[1010] = {};
vector<int> hito[30];

void solve(int current, int cnt, int sol){
    //current คนที่พิจารณาตอนนี้
    if (cnt == n) {
        total = min(sol,total);
        return;
    }

    if (sol >= total || current > m) {
        return;
    }

    for (auto &x: hito[current]) {
        if (day[x] == 0) {
            cnt++;
        }
        day[x]++;
    }

    solve(current+1, cnt, sol+1);
    for (auto &x: hito[current]) {
        if (day[x] == 1) {
            cnt--;
        }
        day[x]--;
    }
    solve(current+1, cnt, sol);
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            hito[i].push_back(x);
        }
    }
    solve(1,0,0);
    cout << total;
}