#include "bits/stdc++.h"
#include <ios>
#include <queue>
#include <utility>

using namespace std;

int r,c;
int grid[5005][5005];
int dist[5005][5005];

int dr[] = {0,0,1,-1};
int dc[] = {-1,1,0,0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c;
    queue<pair<int, int>> q;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];

            if (grid[i][j] == 1) {
                q.push({i,j});
                dist[i][j] = 1;
            }
            else{
                dist[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        int u = q.front().first;
        int v = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = u + dr[i];
            int nc = v + dc[i];

            if (nr >= r || nr < 0 || nc >= c || nc < 0) {
                continue;
            }

            if (grid[nr][nc] == 3) {
                continue;
            }

            if (grid[nr][nc] == 2) {
                cout << dist[u][v] + 1 << endl;
                return 0;
            }

            if (dist[nr][nc] == 0) {
                dist[nr][nc] = dist[u][v] + 1;
                q.push({nr,nc});
            }
        }
    }
}