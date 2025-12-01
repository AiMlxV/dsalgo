#include "bits/stdc++.h"
using namespace std;

void recur(vector<vector<int>> &v, int a, int b,int t,int bo,int l,int r){

    if (a == 0){
        v[t][l] = b;
        return;
    }

    int midRow = (t+bo)/2;
    int midCol = (l+r)/2;

    recur(v, a-1, b, t, midRow, l, midCol);
    recur(v, a-1, b-1, t, midRow, midCol, r);
    recur(v, a-1, b+1, midRow, bo, l, midCol);
    recur(v, a-1, b, midRow, bo, midCol, r);
}

int main(){
    int a,b;
    cin >> a >> b;
    vector<vector<int>> table(1<<a,vector<int>(1<<a));

    recur(table, a, b, 0, 1<<a, 0, 1<<a);

        for (int i = 0; i < 1<<a; i++) {
        for (int  j = 0; j < 1<<a; j++) {
            cout << table[i][j] << " ";
        }
        cout << "\n";
    }
}