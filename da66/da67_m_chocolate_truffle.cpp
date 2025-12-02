#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long R, C;
    int k;
    if (!(cin >> R >> C >> k)) return 0;
    long long N = R * C;

    vector<long long> favs(k);
    for (int i = 0; i < k; i++) {
        long long r, c;
        cin >> r >> c; //store 1D idx
        favs[i] = (r - 1) * C + (c - 1); 
    }

    sort(favs.begin(), favs.end());

    int Q;
    cin >> Q;
    while (Q--) {
        long long r_start, c_start;
        cin >> r_start >> c_start;
        
        long long current_idx = (r_start - 1) * C + (c_start - 1);
        auto it = lower_bound(favs.begin(), favs.end(), current_idx);

        if (it != favs.end()) {
            cout << (*it - current_idx) << "\n";
        } else {
            cout << (N - current_idx) + favs[0] << "\n";
        }
    }

    return 0;
}