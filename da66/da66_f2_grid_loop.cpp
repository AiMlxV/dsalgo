#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005; // 1000x1000
int parent[MAXN], sz[MAXN]; // เก็บพ่อของกลุ่ม และ ขนาดของกลุ่ม
int grid[1005][1005];
int mask[] = {0, 10, 5, 3, 6, 12, 9}; // แปลงท่อเป็น Bit: N=1, E=2, S=4, W=8

// Find Function ของ DSU
int find(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int R, C; cin >> R >> C;
    
    // 1. Init DSU
    for (int i = 0; i < R*C; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < R; i++) 
        for (int j = 0; j < C; j++) 
            cin >> grid[i][j];

    int loop_count = 0, max_len = 0;

    // 2. ไล่เช็คแค่ "ขวา" และ "ล่าง" (เพื่อไม่ให้เช็คซ้ำ)
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int u = i * C + j; // แปลงพิกัด (i,j) เป็น ID ตัวเลขเดียว
            
            // เช็คทางขวา (ทิศ East=2 เจอ West=8)
            if (j + 1 < C && (mask[grid[i][j]] & 2) && (mask[grid[i][j+1]] & 8)) {
                int v = i * C + (j + 1);
                int rootU = find(u), rootV = find(v);
                if (rootU != rootV) { // คนละกลุ่ม รวมร่างกัน
                    parent[rootU] = rootV;
                    sz[rootV] += sz[rootU];
                } else { // กลุ่มเดียวกันอยู่แล้ว = เจอ Loop!
                    loop_count++;
                    max_len = max(max_len, sz[rootU]);
                }
            }
            
            // เช็คทางล่าง (ทิศ South=4 เจอ North=1)
            if (i + 1 < R && (mask[grid[i][j]] & 4) && (mask[grid[i+1][j]] & 1)) {
                int v = (i + 1) * C + j;
                int rootU = find(u), rootV = find(v);
                if (rootU != rootV) {
                    parent[rootU] = rootV;
                    sz[rootV] += sz[rootU];
                } else {
                    loop_count++;
                    max_len = max(max_len, sz[rootU]);
                }
            }
        }
    }

    cout << loop_count << " " << max_len;
    return 0;
}