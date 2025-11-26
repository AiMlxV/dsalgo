#include "bits/stdc++.h"
#include <cstddef>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    size_t table[n+1][n+1];
    for (int i = 0; i <= n; i++) {
        table[i][0] = 1;
        table[i][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            table[i][j] = table[i-1][j] + table[i-1][j-1];
        }
    }
    cout << table[n][k];
}