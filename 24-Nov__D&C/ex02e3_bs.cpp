#include "bits/stdc++.h"
#include <algorithm>
#include <ios>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main(){
    int n,m,input;
    cin >> n >> m;

    vector<int> data;

    while (n--) {
        cin >> input;
        data.push_back(input);
    }

    while (m--) {
        cin >> input;
        // auto it = find(data.begin(),data.end(),input);
        // if (it == data.end()) {
        //     cout << "0";
        //     continue;
        // }

        auto it_find = upper_bound(data.begin(),data.end(),input);
        --it_find;
        // if (*it_find == input) {
            cout << it_find - data.begin() << endl;
            continue;
        // }
        // else if(it_find == data.end()){
        //     cout << "-1" << endl;
        // }
        // else if (*it_find != input) {
        //     cout << "0" << endl;
        //     continue;
        // }
    }

}