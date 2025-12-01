#include "bits/stdc++.h"

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int arr[n][n];
    memset(arr, 0, sizeof(arr));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> arr[i][j];
        }
    }

    //buttom-up
    for (int i = n-2; i >= 0; --i) { //last-second floor
        for (int j = 0; j <= i; ++j) {
            arr[i][j] += max(arr[i+1][j], arr[i+1][j+1]);
        }
    }

    cout << arr[0][0] << "\n";
}