#include "bits/stdc++.h"

using namespace std;

bool dfs(int current, int parent, vector<vector<int>> &adj, vector<bool> vis){
    // #step 1
    vis[current] = true;

    // #step 2
    for (auto &v : adj[current]) {

        // #step 3
        if (vis[v] == false) {
            // #step 3.1
            if(dfs(v, current, adj, vis)){
                return true;
            }
        }
        // #step 4
        else if (v != parent) {
            return true;
        }
    }
    // #step 5
    return false;
}

bool is_Cycle(vector<vector<int>> &v, int n){
    vector<bool> visited(n,false);

    for (int u = 0; u < n; u++) {
        if (visited[u] == false) {
            if (dfs(u, -1, v, visited)) {
                return true;
            }
        }
    }
    return false;
}

int main(){
    int t,n,e;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> e;
        vector<vector<int>> graph(n);
        int v1,v2;
        for (int j = 0; j < e; j++) {
            cin >> v1 >> v2;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }

        if (is_Cycle(graph,n)) {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}
