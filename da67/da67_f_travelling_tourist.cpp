#include<bits/stdc++.h>
using namespace std;
long long dis[505][505]; 
int n, m, k, l, r, w;
int q[10];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dis[i][j] = 0; // ตัวเองไปตัวเองเป็น 0
            else dis[i][j] = 1e9;      // คนอื่นเป็น Infinity
        }
    }
    for (int i = 0; i < k; i++) cin >> q[i];
    for (int i = 0; i < m; i++){
        cin >> l >> r >> w;
        // ต้อง cast เป็น long long หรือใช้ min แบบระวัง type
        if (w < dis[l][r]) {
            dis[l][r] = w;
            dis[r][l] = w;
        }
    }
    for (int i = 1; i <= n; i++){ 
        for (int j = 1; j <= n; j++){
            for (int p = 1; p <= n; p++){
                // เช็คกัน Overflow และลดรอบที่ไม่จำเป็น
                if (dis[j][i] != 1e9 && dis[i][p] != 1e9) {
                    dis[j][p] = min(dis[j][p], dis[j][i] + dis[i][p]);
                }
            }
        }
    }

    long long mn = 1e18;
    sort(q, q + k);

    do {
        long long t = 0;
        bool valid = true;
        for (int i = 0; i < k - 1; i++) {
            if (dis[q[i]][q[i+1]] == 1e9) {
                valid = false; 
                break;
            }
            t += dis[q[i]][q[i+1]];
        }
        if (valid) mn = min(mn, t);
    } while (next_permutation(q, q + k));

    cout << mn;
}