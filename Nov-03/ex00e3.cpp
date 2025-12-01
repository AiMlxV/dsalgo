#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    set<int> s;
    int x;
    
    for (int i = 0; i < N; i++) {
        cin >> x;
        s.insert(x);
    }

    if ((int)s.size() != N) {
        cout << "NO\n";
        return 0;
    }

    int expected = 1;
    for (int val : s) {
        if (val != expected) {
            cout << "NO\n";
            return 0;
        }
        expected++;
    }

    cout << "YES\n";
    return 0;
}
