#include "bits/stdc++.h"

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    long long k;
    cin >> k;

    vector<long long> grass_field(n);

    for(int i = 0; i < n; i++){
        cin >> grass_field[i];
    }

    //prefix sum
    vector<long long> qs_grass(n+1,0);
    vector<long long> qs_cost(n+1,0);

    for(int i = 0; i < n; ++i){
        qs_grass[i+1] = qs_grass[i] + grass_field[i];

        qs_cost[i+1] = qs_cost[i] + (grass_field[i]+k);
    }

    //query part
    for(int i = 0; i < m; ++i){
        int start;
        long long budget;
        cin >> start >> budget;

        long long maximum = budget + qs_cost[start];

        auto possible = upper_bound(qs_cost.begin()+start,qs_cost.end(),maximum);

        int end = distance(qs_cost.begin(), possible) - 1;

        long long result = qs_grass[end] - qs_grass[start];

        cout << result << endl;
    }
}