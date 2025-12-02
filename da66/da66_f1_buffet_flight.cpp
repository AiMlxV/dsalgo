#include "bits/stdc++.h"
using namespace std;
#define INF 1e9
int n,m;
vector<int> ci;
vector<int> co;
int main(){
    cin >> n >> m;
    ci.resize(n);
    co.resize(n);

    for(int i = 0; i < n; i++){
        cin >> ci[i];
    }
    for(int i = 0; i < n; i++){
        cin >> co[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    vector<int> dist(n,INF);
    priority_queue<pair<int, int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[0] = 0;
    pq.push({0,0}); //{xost,id}

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (w > dist[u]) {
            continue;
        }

        for (auto &v : adj[u]) {
            int weight = co[u] + ci[v];

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v],v});
            }
        }
    }

    for(int i = 0; i < n; i++){
        if (dist[i] == INF) {
            cout << -1 << " ";
        }
        else{
            cout << dist[i] << " ";
        }
    }
    cout << endl;
}