#include "bits/stdc++.h"
#include <cstddef>
#include <cstdlib>
#include <ios>
#include <sstream>
#include <string>

using namespace std;

bool check (const string &s){
    int len = s.length();

    if (len == 1) {
        return true; // cannot div any more
    }

    int mid = len/2;
    string left = s.substr(0,mid);
    string right = s.substr(mid);

    int left_cnt = 0;
    for (char &c: left) {
        if (c == '1') {
            left_cnt+=1;
        }
    }

    int right_cnt = 0;
    for (char &c: right) {
        if (c == '1') {
        right_cnt+=1;
        }
    }

    if (abs(left_cnt-right_cnt) > 1) {
        return false;
    }

    return check(left) && check(right);

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        string s = "";
        for (int j = 0; j< (1<<k); j++) {
            string c;
            cin >> c;
            s += c;
        }

        if (check(s)) {
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
    }
}