#include <iostream>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, v;
    while (cin >> n >> k >> v) {
        list<int> a;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a.push_back(x);
        }

        auto it = a.begin();
        advance(it, k);     
        it = a.insert(it, v);   

        bool exploded = true;
        while (exploded && !a.empty()) {
            exploded = false;

            auto left = it, right = it;
            int color = *it;
            int count = 1;

            while (left != a.begin()) {
                auto prev = left; --prev;
                if (*prev != color) break;
                left = prev;
                count++;
            }
            while (next(right) != a.end() && *next(right) == color) {
                right++;
                count++;
            }

            if (count >= 3) {
                right++;
                it = a.erase(left, right);
                exploded = true;

                if (it != a.begin() && it != a.end()) --it;
                else if (it == a.end() && !a.empty()) --it;
            }
        }

        if (a.empty()) cout << 0 << '\n';
        else {
            bool first = true;
            for (auto &x : a) {
                if (!first) cout << ' ';
                cout << x;
                first = false;
            }
            cout << '\n';
        }
    }
}
