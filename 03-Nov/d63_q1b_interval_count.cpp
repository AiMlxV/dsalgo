#include "iostream"
#include <algorithm>
#include <vector>
#include <set>

#define hayai std::ios_base::sync_with_stdio(false); std::cin.tie(0); 

using namespace std;

int main(){
    hayai;
    int n,m,k,input,p;
    vector<int> ans;
    vector<int> jod;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> input;
        jod.push_back(input);
    }

    sort(jod.begin(), jod.end());
    
    for (int i = 0; i < m; i++) {
        cin >> input;
        p = input;
        int lower = p - k;
        int upper = p + k;
        auto it1 = lower_bound(jod.begin(),jod.end(),lower);
        auto it2 = upper_bound(jod.begin(),jod.end(),upper);
        auto cnt = it2 - it1;
        ans.push_back(cnt);
    }
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << endl;
}