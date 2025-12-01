#include "map_bst.h"
#include "student.h"
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, d;
    std::cin >> n >> d;
    CP::map_bst<int, int> mp;

    for (int i = 0; i < n; i++) {
        int key;
        std::cin >> key;
        mp[key] = i;
    }

    std::cout << mp.parity_score(d) << '\n';
    return 0;
}
