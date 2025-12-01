#include "bits/stdc++.h"
#include <algorithm>
#include <ios>
#include <vector>

using namespace std;

#define INF 1e9

int ans = -1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> dist(n,vector<int>(n));
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            cin >> dist[i][j];
            if (dist[i][j] == -1){
                dist[i][j] = INF;
            }
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            if(k == n-1 && i == 0){
                ans = max(ans,dist[i][j]);
                }
            }
        }
    }

    if (ans == INF) {
        cout << "-1";
    }
    else{
        cout << ans;
    }
    cout << "\n";
}
