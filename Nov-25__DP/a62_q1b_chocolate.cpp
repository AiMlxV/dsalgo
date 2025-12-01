#include "bits/stdc++.h"
#include <vector>

using namespace std;

int main(){
    int n,k;
    
    cin >> n >> k;

    vector<int> s(k);
    for(int i = 0; i < k; i++){
        cin >> s[i];
    }

    vector<int> dp(n+1,0);

    dp[0] = 1;

    int mod = 1000003;

    for (int i = 1; i <= n; ++i) {
        for (auto &x : s) {
            if (i >= x) {
                dp[i] = (dp[i] + dp[i - x])%mod;
            }
        }
    }

    cout << dp[n] << "\n";

    return 0;
}