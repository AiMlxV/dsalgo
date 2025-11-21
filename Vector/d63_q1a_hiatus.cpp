#include "bits/stdc++.h"

using namespace std;

int main(){
    int n , m;
    cin >> n >> m;
    int years, month;
    set<pair<int, int>> timeline;
    for (int i = 0; i < n; i++) {
        cin >> years >> month;
        timeline.insert({years,month});
    }
    for (int i = 0; i < m; ++i) {
        cin >> years >> month;
        pair<int,int> q{years, month};
        if (timeline.find(q) != timeline.end()) {
            cout << "0 0 ";
            continue;
        }
        auto it = timeline.lower_bound(q);
        if (it == timeline.begin()) {
            cout << "-1 -1 ";
        } else {
            --it;
            cout << it->first << ' ' << it->second << ' ';
        }
    }
}