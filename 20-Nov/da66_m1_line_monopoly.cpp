#include "bits/stdc++.h"
#include <climits>
#include <iterator>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
    int n,start,end,op_code;
    set<pair<int, int>> monopoly;
    cin >> n;
    while (n--) {
        cin >> op_code;
        if (op_code == 1) {
            cin >> start >> end;
            auto it = monopoly.lower_bound({start,INT_MIN});
            //find the left_bond
            if (it != monopoly.begin()) {
                it--;
                if(it->second < start - 1){
                    it++;
                }
            }
            //find duplicate
            while(it != monopoly.end() && it->first <= end + 1){
                start = min(start, it->first);
                end = max(end, it->second);
                it = monopoly.erase(it);
            }
            //insert new range
            monopoly.insert({start,end});
        }
        else{
            cout << monopoly.size() << "\n";
        }
    }
}