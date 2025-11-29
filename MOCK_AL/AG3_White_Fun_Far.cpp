#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    long long c = 1, e = 1, d = 1, t = 1;
    long long MOD = 100000007;

    for (int i = 2; i <= N; i++) {
        long long nc = (d + t) % MOD;
        long long ne = (c + t) % MOD;
        long long nd = e % MOD;
        long long nt = c % MOD;

        c = nc;
        e = ne;
        d = nd;
        t = nt;
    }

    cout << (c + e + d + t) % MOD << "\n";

    return 0;
}
