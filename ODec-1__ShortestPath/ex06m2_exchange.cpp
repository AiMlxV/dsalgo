#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;

    vector<vector<double>> dist(N, vector<double>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> dist[i][j];
        }
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                dist[i][j] = max(dist[i][j], dist[i][k] * dist[k][j]);
            }
        }
    }

    bool has_cycle = false;
    for (int i = 0; i < N; ++i) {
        if (dist[i][i] > 1.0) {
            has_cycle = true;
            break;
        }
    }

    if (has_cycle) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int K;
    if (cin >> K) {
        while (K--) {
            solve();
        }
    }
    return 0;
}