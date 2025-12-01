#include "bits/stdc++.h"
#include <algorithm>
#include <cstddef>
#include <vector>

using namespace std;

int main(){
    vector<size_t> unsorted_vec;
    size_t n , m, input;
    cin >> n >> m;
    while (n--) {
        cin >> input;
        unsorted_vec.push_back(input);
    }

    while (m--) {
        size_t cnt = 0;
        cin >> input;
        auto it = find(unsorted_vec.begin(),unsorted_vec.end(),input);
        for (;it > unsorted_vec.begin()-1; it--) {
            if (((*it) > input) ) {
                ++cnt;
            }
        }
        cout << cnt << "\n";
    }
}