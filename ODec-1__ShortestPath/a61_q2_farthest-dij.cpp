#include "bits/stdc++.h"
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

const int INF = 1e9;

int main(){
    int n;
    cin >> n;

    vector<vector<int>> adj (n,vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int u = i;
            int v = j;
            cin >> adj[u][v];
        }
    }

    vector<int> dist(n,INF);
    vector<bool> visited(n,false);

    dist[0] = 0; //itself

    for (int i = 0; i < n; i++) {
        int u = -1;
        int min_val = INF;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min_val) {
                min_val = dist[j];
                u = j;
            }
        }

        if (u == -1 || dist[u] == INF) {
            break;
        }

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            int w = adj[u][v];

            if (w != -1) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

    }

    int max_dist = 0;
    for (int i = 0; i < n; i++) {
        if(dist[i] == INF){
            cout << "-1" << endl;
            exit(0);
        }

        if (dist[i] > max_dist) {
            max_dist = dist[i];
        }
    }

    cout << max_dist << endl;
    exit(0);

}