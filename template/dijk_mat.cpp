#include "bits/stdc++.h"

void dijkstra_matrix(int start, int n, vector<vector<int>>& matrix) {
    vector<int> dis(n, 1e9);
    vector<bool> visited(n, false);
    
    dis[start] = 0;

    // Matrix มักไม่ใช้ PQ แต่ใช้วิธีวนหาตัวน้อยสุด O(N^2)
    for(int i = 0; i < n; i++) {
        int u = -1;
        // หาโหนดที่ distance น้อยสุดที่ยังไม่ visit
        for(int j = 0; j < n; j++) {
            if(!visited[j] && (u == -1 || dis[j] < dis[u]))
                u = j;
        }

        if(dis[u] == 1e9) break; // ไปต่อไม่ได้แล้ว
        visited[u] = true;

        // Loop 1..N เพื่อหาว่าใครเชื่อมกับ u บ้าง
        for(int v = 0; v < n; v++) {
            if(matrix[u][v] != 0 && matrix[u][v] != 1e9) { // มีเส้นเชื่อม
                if(dis[u] + matrix[u][v] < dis[v]) {
                    dis[v] = dis[u] + matrix[u][v];
                }
            }
        }
    }
}