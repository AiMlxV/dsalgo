#include "bits/stdc++.h"
#include <cstddef>
#include <utility>
#include <vector>

using namespace std;

int main(){
    size_t n, m, start, date, diff;
    vector<pair<size_t, size_t>> change_keep;
    size_t pocket = 0;
    cin >> n >> m >> start;
    for (int i = 0; i < n; i++) {
        cin >> date >> diff;
        change_keep.push_back(make_pair(date, diff));
    }
    pocket += start;
    size_t price ,date_pickpocket;
    for (int i = 0; i < m; i++) {
        if (pocket[date_pickpocket] >= price) {
            find which date before that money in pocket can buy (include this day)
        else
            start keeping again by including chage keeping money date  by checking each date by lower bond nearest date in changekeep vector
            check untill we can buy the icecream
        }
    }
}