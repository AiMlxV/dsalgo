#include "bits/stdc++.h"

using namespace std;

int bfs(int start, int N, int K, vector<vector<int>> &adj){
    vector<bool> visited(N+1,false);

    queue<pair<int, int>> q;

    q.push({start,0});
    visited[start] = true;

    int cnt = 0;

    while (!q.empty()) {
        int u = q.front().first;
        int layer = q.front().second;
        q.pop();

        cnt+=1;

        if (layer < K) {
            for (auto &v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;

                    q.push({v,layer+1});
                }
            }
        }

    }

    return cnt;
}

int main(){
    int n,e,k;
    cin >> n >> e >> k;

    vector<vector<int>> adj(n);
    for (int i = 0; i < e; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int max_friends = -1;

    for(int i = 0; i< n; i++){
        int friend_cnt = bfs(i, n, k, adj);

        if (friend_cnt > max_friends) {
            max_friends = friend_cnt;
        }

    }

    cout << max_friends << endl;
    // bfs(0, n, k, adj);
    
}