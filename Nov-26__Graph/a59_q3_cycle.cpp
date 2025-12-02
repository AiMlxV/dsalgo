#include "bits/stdc++.h"
#include <cstdlib>
#include <ios>
#include <iostream>
#include <variant>
#include <vector>
using namespace std;
vector<int> adj[100005];
int depth[100005];
bool visited[100005];

void dfs(int u, int parent, int d){
    visited[u] = true;
    depth[u] = d;
    for (auto &v : adj[u]) {
        if (v == parent) {
            continue;
        }
        
        if (!visited[v]) {
            dfs(v, u, d+1);
        }
        else{
            int cycle_size = abs(depth[u] - depth[v]) + 1;
            cout << cycle_size << endl;
            exit(0);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    for (int i =0 ; i < n; i++) {
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0 , -1, 0);
}
