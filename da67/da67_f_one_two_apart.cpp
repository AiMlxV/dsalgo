#include "bits/stdc++.h"
using namespace std;
#define m 100000007
int main(){
    long long n;
    cin >> n;
    vector<long long> dp1(n+1,0), dp2(n+1,0), dp10(n+1,0), dp20(n+1,0), dp00(n+1,0);
    dp00[1] = 1;
    dp1[1] = 1;
    dp2[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp1[i] = (dp1[i-1] + dp10[i-1]+ dp00[i-1])%m;

        dp2[i] = (dp2[i-1] + dp20[i-1]+ dp00[i-1])%m;
        
        dp10[i] = dp1[i-1];
        dp20[i] = dp2[i-1];
    
        dp00[i] = (dp10[i-1] + dp20[i-1] + dp00[i-1])%m;
    }
    cout << (dp00[n]+dp1[n]+dp2[n]+dp10[n]+dp20[n])%m;
}