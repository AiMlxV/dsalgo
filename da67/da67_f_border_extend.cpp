#include "bits/stdc++.h"
#include <cstddef>
#include <ios>
#include <queue>
#include <utility>

using namespace std;

#define INF 1e9
int R,C,K;
int grid[1005][1005];
int dist[1005][1005];

int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C >> K;

    queue<pair<int, int>> q;

    for(int i = 0; i < R; i++){
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
            dist[i][j] = -1;

            if (grid[i][j] == 1) {
                dist[i][j] = 0;
                q.push({i,j});
            }
        }
    }

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if (dist[r][c] >= K) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 1 || nr <= R && nc >= 1 || nc <= C) {
                if(dist[nr][nc] == -1){
                    dist[nr][nc] = dist[r][c] + 1;
                    grid[nr][nc] = 2;
                    q.push({nr,nc});
                }
            }
        }
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    
}