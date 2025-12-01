#include "bits/stdc++.h"

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int R,C,t;
    cin >> R >> C >> t;

    vector<vector<int>> hito(R, vector<int>(C));

    queue<pair<int, int>> q;
    int infect_cnt = 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> hito[i][j];

            if (hito[i][j] == 1) {
                q.push({i,j});
                infect_cnt+=1;
            }
        }
    }

    int dr[] = {-1,1,0,0};
    int dc[] = {0,0,-1,1};

    int current_day = 0;

    while (!q.empty() && current_day < t) {
        int today_size = q.size();

        while (today_size--) {
            pair<int, int> data = q.front();
            q.pop();

            int r = data.first;
            int c = data.second;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                
                    if (hito[nr][nc] == 0) {
                        hito[nr][nc] = 1;
                        infect_cnt+=1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        current_day+=1;
    }

    cout << infect_cnt << "\n";
}