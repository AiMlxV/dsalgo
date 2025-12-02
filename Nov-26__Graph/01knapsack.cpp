#include "bits/stdc++.h"
using namespace std;
int main() {
    int W, N; 
    cin >> W >> N;

    vector<double> v(N), w(N);
    for(int i=0; i<N; i++) cin >> v[i];
    for(int i=0; i<N; i++) cin >> w[i];
    // dp[j] = มูลค่าสูงสุดที่น้ำหนัก j
    // ใช้ vector<double> เพราะราคาอาจเป็นทศนิยมได้
    vector<double> dp(W + 1, 0.0);
    for (int i = 0; i < N; i++) {
        int weight_int = (int)w[i];    
        for (int j = W; j >= weight_int; j--) {
            dp[j] = max(dp[j], dp[j - weight_int] + v[i]);
        }
    }

    cout << fixed << setprecision(4) << dp[W] << endl;
    return 0;
}