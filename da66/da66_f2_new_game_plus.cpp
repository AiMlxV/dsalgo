#include <iostream>
#include <vector>
using namespace std;
const int MOD = 100000007;
int R, C;
int grid[505][505];
// dp[row][last_move] เก็บจำนวนวิธีของคอลัมน์ปัจจุบัน
long long dp[505][3]; 
// next_dp เก็บค่าของคอลัมน์ถัดไปที่เรากำลังคำนวณ
long long next_dp[505][3];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (!(cin >> R >> C)) return 0;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> grid[i][j];
        }
    }
    // --- ขั้นตอนที่ 1: จัดการก้าวแรก (จาก Col 1 -> Col 2) ---
    for (int r = 1; r <= R; r++) {
        if (grid[r][2] == 1) continue; // ถ้าปลายทางตัน ข้ามเลย
        // ท่า X (0): มาจาก (r+1, 1)
        if (r + 1 <= R && grid[r+1][1] == 0) dp[r][0] = 1;
        // ท่า Y (1): มาจาก (r, 1)
        if (grid[r][1] == 0) dp[r][1] = 1;
        // ท่า Z (2): มาจาก (r-1, 1)
        if (r - 1 >= 1 && grid[r-1][1] == 0) dp[r][2] = 1;
    }
    // --- ขั้นตอนที่ 2: ไล่คำนวณ Col 3 จนถึง Col C ---
    for (int c = 3; c <= C; c++) {
        // เคลียร์ค่าในตาราง next_dp
        for(int r = 0; r <= R + 1; r++) {
            next_dp[r][0] = next_dp[r][1] = next_dp[r][2] = 0;
        }
        for (int r = 1; r <= R; r++) {
            if (grid[r][c] == 1) continue; // ถ้าช่องนี้ห้ามเข้า ข้าม
            // 1. คำนวณการมาถึงด้วยท่า X (มาจาก r+1)
            if (r + 1 <= R) {
                next_dp[r][0] = (dp[r+1][1] + dp[r+1][2]) % MOD;
            }
            // 2. คำนวณการมาถึงด้วยท่า Y (มาจาก r)
            next_dp[r][1] = (dp[r][0] + dp[r][2]) % MOD;
            // 3. คำนวณการมาถึงด้วยท่า Z (มาจาก r-1)
            if (r - 1 >= 1) {
                next_dp[r][2] = (dp[r-1][0] + dp[r-1][1]) % MOD;
            }
        }
        for(int r = 1; r <= R; r++) {
            for(int k = 0; k < 3; k++) dp[r][k] = next_dp[r][k];
        }
    }
    long long ans = 0;
    for (int r = 1; r <= R; r++) {
        ans = (ans + dp[r][0] + dp[r][1] + dp[r][2]) % MOD;
    }
    cout << ans << endl;
    return 0;
}