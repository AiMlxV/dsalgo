#include "bits/stdc++.h"
#include <functional>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
#define INF 1e9
using edges = pair<int, pair<int, int>>;

int main(){
    int r,c;
    cin >> r >> c;

    vector<vector<int>> cost(r,vector<int>(c));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> cost[i][j];
        }
    }

    vector<vector<int>> dist(r,vector<int>(c, INF));

    priority_queue<edges, vector<edges>, greater<edges>> pq;

    dist[0][0] = 0;

    pq.push({0,{0,0}});

    int dr[] = {-1,1,0,0};
    int dc[] = {0,0,-1,1};

    while (!pq.empty()) {
        
        int w = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;

        pq.pop();

        if (w > dist[u][v]) {
            continue;
        }

        for(int i = 0; i < 4; i++){
            int nr = u + dr[i];
            int nc = v + dc[i];

            if (nr >= 0 && nr < r && nc >= 0 && nc < c) {
                int new_dist = dist[u][v] + cost[nr][nc];

                if (new_dist < dist[nr][nc]) {
                    dist[nr][nc] = new_dist;

                    pq.push({new_dist,{nr,nc}});
                }
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << dist[i][j] << " ";
        }
        cout << "\n"; 
    }
}