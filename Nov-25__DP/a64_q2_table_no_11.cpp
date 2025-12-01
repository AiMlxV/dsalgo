#include "bits/stdc++.h"

using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> dp0_0(n+1,0), dp0_1or1_0(n+1,0);
    dp0_0[1] = 1;
    dp0_1or1_0[1] = 1;
    for(int i = 2; i <= n; i++){
        dp0_0[i] = (dp0_0[i-1]+(dp0_1or1_0[i-1]*2))%100000007;
        dp0_1or1_0[i] = (dp0_0[i-1]+dp0_1or1_0[i-1])%100000007;
    }
    cout << ((dp0_0[n]+(dp0_1or1_0[n]*2))%100000007);
}