#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 5005;
int r, c, dist[N][N];
string g[N];
vector<pii> popbus[10];
deque<pii> dq;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> r >> c;
    memset(dist, 0x3f, sizeof(dist)); // Init with INF
    for (int i = 0; i < r; i++) {
        cin >> g[i];
        for (int j = 0; j < c; j++)
            if (isdigit(g[i][j])) popbus[g[i][j] - '0'].push_back({i, j});
    }
    dist[0][0] = 0;
    dq.push_back({0, 0});
    while (!dq.empty()) {
        auto [cr, cc] = dq.front(); dq.pop_front();
        // 1. Teleport (Cost 0 -> push_front)
        if (isdigit(g[cr][cc])) {
            int n = g[cr][cc] - '0';
            if (popbus[n].size() == 2) {
                pii to = (popbus[n][0] == make_pair(cr, cc)) ? popbus[n][1] : popbus[n][0];
                if (cr + cc < to.first + to.second && dist[to.first][to.second] > dist[cr][cc]) {
                    dist[to.first][to.second] = dist[cr][cc];
                    dq.push_front(to);
                }
            }
        }
        // 2. Walk (Cost 1 -> push_back)
        int dr[] = {0, 0, 1}, dc[] = {-1, 1, 0};
        for (int i = 0; i < 3; i++) {
            int nr = cr + dr[i], nc = cc + dc[i];
            if (nr >= 0 && nr < r && nc >= 0 && nc < c && g[nr][nc] != 'X' && dist[nr][nc] > dist[cr][cc] + 1) {
                dist[nr][nc] = dist[cr][cc] + 1;
                dq.push_back({nr, nc});
            }
        }
    }
    cout << dist[r - 1][c - 1];
}
