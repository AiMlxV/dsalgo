void floyd_warshall(int n, vector<vector<int>>& dis) {
    // k = จุดผ่าน, i = ต้นทาง, j = ปลายทาง
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dis[i][k] != 1e9 && dis[k][j] != 1e9) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }
}