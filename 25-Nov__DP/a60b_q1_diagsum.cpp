#include "bits/stdc++.h"
#include <algorithm>
#include <climits>

using namespace std;

int main(){
    int n;
    int maximum = INT_MIN;

    cin >> n;
    int arr[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if(i > 0 and j > 0){
                arr[i][j] = max(arr[i][j], arr[i][j]+arr[i-1][j-1]);
                maximum = max(maximum,arr[i][j]); 
            }
        }
    }

    cout << maximum << endl;
}