void dijkstra_list(int start, int n, vector<vector<pair<int,int>>>& adj) {
    vector<int> dis(n, 1e9);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dis[start] = 0;
    pq.push({0, start}); // {distance, node}

    while(!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d > dis[u]) continue;

        // Loop ตาม Neighbor ใน List
        for(auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if(dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w; // *** จุดต่างกับ Prim คือตรงนี้ (บวกระยะสะสม)
                pq.push({dis[v], v});
            }
        }
    }
}