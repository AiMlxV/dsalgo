#include "bits/stdc++.h"

using namespace std;

void dfs(int current, vector<vector<int>> &adj, vector<bool> &vis){
    vis[current] = true;
    for (auto &v : adj[current]) {
        if (vis[v] == false) {
            dfs(v, adj, vis);
        }
    }
}

int cc(vector<vector<int>> &adj , int adj_size){
    int cnt = 0;
    vector<bool> vis(adj_size);
    for (int i = 0; i < adj_size; i++) {
        if (vis[i] == false) {
            cnt+=1;
            dfs(i,adj,vis);
        }
    }
    return cnt;
}

int main(){
    int v,e,v1,v2;
    cin >> v >> e;
    vector<vector<int>> graph(v);
    for (int i = 0; i < e; i++) {
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    cout << cc(graph,v) << endl;
}