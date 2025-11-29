//for education purpose
#include "bits/stdc++.h"

using namespace std;

int r,c;
int dist[5005][5005];
string g[5005];
vector<pair<int, int>> popbus[10];
deque<pair<int, int>> dq;

void update(int r_u, int c_u, int d, bool can_tp){
    if (r_u < 0 or c_u < 0 or r_u >= r or c_u >= c or g[r_u][c_u] == 'X' or dist[r_u][c_u] <= d) {
        return;
    }
    dist[r_u][c_u] = d;
    if (can_tp) {
        dq.push_front({r_u,c_u});
    }
    else {
        dq.push_back({r_u,c_u});
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> r >> c;
    memset(dist, 0x3f, sizeof(dist));
    
    for (int i = 0; i < r; i++) {
        cin >> g[i];
        for (int j = 0; j < c; j++) {
            if (isdigit(g[i][j])) {
                popbus[g[i][j] - '0'].push_back({i,j});
            }
        }
    }

    update(0, 0, 0, 1);

    while (!dq.empty()) {
        auto [cr,cc] = dq.front();
        dq.pop_front();

        if (isdigit(g[cr][cc])) {
            int n = g[cr][cc] - '0';
            if (popbus[n].size() == 2) {

                auto tp_to = popbus[n][0];
                if (popbus[n][0] == make_pair(cr, cc)) {
                    tp_to = popbus[n][1];
                }

                if (cr+cc < tp_to.first + tp_to.second) {
                    update(tp_to.first, tp_to.second, dist[cr][cc], 1);
                }
            }
        }

        int dr[] = {0,0,1};
        int dc[] = {-1,1,0};

        for (int i = 0; i < 3; i++) {
            update(cr + dr[i], cc + dc[i], dist[cr][cc] + 1, 0);
        }
    }
    cout << dist[r - 1][c - 1];
}