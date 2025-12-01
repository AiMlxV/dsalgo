#include "bits/stdc++.h"
#include <ios>
#include <utility>
#include <vector>

using namespace std;

const int INF = 1e9;

vector<pair<int, int>> adj[705];

int dijk(int cur_n){
    vector<int> dist (cur_n + 1,INF);
    vector<bool> visited(cur_n+1,false);

    dist[1] = 0;

    for(int i = 1; i <= cur_n; i++){
        int u = -1;
        int min_val = INF;

        for (int j = 1; j <= cur_n; j++) {
            if (!visited[j] && dist[j] < min_val) {
                min_val = dist[j];
                u = j;
            }
        }

        if (u == -1 || dist[u] == INF) {
            break;
        }

        if (u == 2) {
            return dist[2];
        }

        visited[u] = true;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u]+w;
            }
        }
    }
    return dist[2];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, init_cost;
    cin >> n >> init_cost;

    adj[1].push_back({2,init_cost});
    adj[2].push_back({1,init_cost});

    for (int i = 3; i <= n; i++) {
        int k;
        cin >> k;

        while (k--) {
            int target,cost;
            cin >> target >> cost;

            adj[i].push_back({target,cost});
            adj[target].push_back({i,cost});
        }

        cout << dijk(i) << " ";
    }
    cout << endl;
}