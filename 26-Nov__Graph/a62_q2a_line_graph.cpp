#include "bits/stdc++.h"

using namespace std;

vector<int> adj[200005];
bool visited[200005];
int degrees[200005];

int c_node = 0;
int c_n_edges = 0;
int max_in_edges = 0;

void dfs(int u){
    visited[u] = true;

    c_node++;
    c_n_edges+=degrees[u];
    max_in_edges = max(max_in_edges,degrees[u]);

    for (auto &v : adj[u]) {
        if(!visited[v]){
            dfs(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,e;
    cin >> n >> e;

    for(int i = 0; i < e; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

        degrees[v]++;
        degrees[u]++;
    }

    int linear_cnt = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            c_node = 0;
            c_n_edges = 0;
            max_in_edges = 0;

            dfs(i);

            int n_edge = c_n_edges/2;

            bool less_than2 = (max_in_edges <= 2);
            bool edges_less = (n_edge == c_node -1);

            if (less_than2&&edges_less) {
                linear_cnt++;
            }
        }
    }

    cout << linear_cnt << "\n";
}