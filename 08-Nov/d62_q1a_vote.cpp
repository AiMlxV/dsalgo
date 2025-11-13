#include "bits/stdc++.h"
#include <algorithm>
#include <cstddef>
#include <functional>
using namespace std;
int main(){
    size_t n,k;
    unordered_map<string, size_t> scoreboard;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        if (scoreboard.find(name) == scoreboard.end()) {
            scoreboard[name] = 1;
        }
        else{
            scoreboard[name]++;
        }
    }

    vector<size_t> rearrange_scoreboard;
    for (auto &x : scoreboard) {
        rearrange_scoreboard.push_back(x.second);
    }

    sort(rearrange_scoreboard.begin(),rearrange_scoreboard.end(),greater<size_t>());
    
    if (rearrange_scoreboard.size() < k) {
        cout << rearrange_scoreboard[rearrange_scoreboard.size()-1];
    }
    else{
        cout << rearrange_scoreboard[k-1];
    }

    return 0;
}