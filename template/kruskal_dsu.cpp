// DSU Functions
int parent[1005];
int find(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i]); // Path Compression
}
void unite(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    if (root_i != root_j) parent[root_i] = root_j;
}

void kruskal(int n, vector<pair<int, pair<int, int>>>& edges) {
    for(int i=0; i<n; i++) parent[i] = i; // Init DSU
    
    sort(edges.begin(), edges.end()); // เรียงน้ำหนักน้อยไปมาก
    
    int mst_weight = 0;
    for(auto &e : edges) {
        int w = e.first;
        int u = e.second.first;
        int v = e.second.second;
        
        if(find(u) != find(v)) { // ถ้ายังไม่เชื่อมกัน (ไม่เกิด Cycle)
            unite(u, v);
            mst_weight += w;
            // cout << "Edge: " << u << "-" << v << endl;
        }
    }
}