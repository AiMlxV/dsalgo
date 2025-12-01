#include "bits/stdc++.h"
#include <utility>
#include <vector>

#define INF 1e9

using namespace std;

int main(){
    int n,e,s;
    cin >> n >> e >> s;

    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < e; i++) {
        int w,u,v;

        cin >> u >> v >> w;
        edges.push_back({w,{u,v}});
    }

    vector<int> dist(n,INF);
    dist[s] = 0;

    for (int i = 0; i < n-1; i++) {
        for (auto &edge : edges) {
            int w = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    bool has_negative_cycle = false;

        for (auto &edge : edges) {
            int w = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                has_negative_cycle = true;
                break;
            }
        }

    if (has_negative_cycle) {
        cout << "-1 ";
    }
    else{
        for(int i = 0; i < n; i++){
            cout << dist[i] << " ";
        }
    }
    cout << endl;
}