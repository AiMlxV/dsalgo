#include "bits/stdc++.h"
#include <algorithm>
#include <ios>
#include <string>
#include <utility>
#include <vector>

using namespace std;

void permu(string str, int curr, int end_size, vector<string> &ans){
    
    if (curr == end_size) {
        // cout << str << endl;
        ans.push_back(str);
    }
    else{
        bool used[256] = {false};

        for (int i = curr; i <= end_size; i++) {

            if (used[str[i]]) {
                continue;
            }

            used[str[i]] = true;

            swap(str[curr],str[i]);
            permu(str, curr+1, end_size,ans);
            swap(str[curr],str[i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string input;
    cin >> input;
    vector<string> ans_set;
    permu(input,0,input.size()-1,ans_set);
    sort(ans_set.begin(),ans_set.end());
    cout << ans_set.size() << "\n";
    for (auto &x : ans_set) {
        cout << x << "\n";
    }
}