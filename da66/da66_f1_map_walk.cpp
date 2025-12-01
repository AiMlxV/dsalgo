#include "bits/stdc++.h"
#include <ios>
#include <string>
#include <vector>

using namespace std;

void solve(string seq, vector<vector<int>> &map, int c_r, int c_c, int r, int c){
    if (c_r == r && c_c == c) {
        cout << seq << endl;
        return;
    }
    if (c_c+1 <= c && map[c_r][c_c+1] != 1) {
        solve(seq + 'A', map, c_r, c_c+1, r, c);
    }
    if (c_r+1 <= r && seq[seq.length()-1] != 'C' && map[c_r+1][c_c] != 1) {
        solve(seq + 'B', map, c_r+1, c_c, r, c);
    }
    if (c_r-1 > 0 && seq[seq.length()-1] != 'B' && map[c_r-1][c_c] != 1) {
        solve(seq + 'C', map, c_r-1, c_c, r, c);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int r,c;
    cin >> r >> c;

    vector<vector<int>> map(r+1,vector<int>(c+1)); 
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> map[i][j];
        }
    }

    string seq = "";
    solve(seq,map,1,1,r,c);
    cout << "DONE" << endl;
}