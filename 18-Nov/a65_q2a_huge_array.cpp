#include "bits/stdc++.h"
// #include <utility>
// #include <algorithm>
// #include <cstddef>
// #include <map>
// #include <utility>
// #include <vector>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    size_t n,q,number,haw_many,verymuch=0;
    cin >> n >> q;
    map<int, int> counting_technics;
    while (n--) {
        cin >> number >> haw_many;
        counting_technics[number] += haw_many;
    }

    vector<pair<size_t, int>> counting;
    size_t current_limit = 0;
    for (auto const &[id ,count] : counting_technics) {
        current_limit += count;
        counting.push_back({current_limit,id});
    }

    while (q--) {
        cin >> number;
        auto finder = lower_bound(counting.begin(),counting.end(),make_pair(number, 0));

        if (finder!=counting.end()) {
            cout << finder->second << "\n";
        }
        else{
            cout << "How?";
        }
        
    }
    return 0;
}