#include "bits/stdc++.h"
#include <functional>
#include <ios>
#include <queue>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N,D,T,Z;
    cin >> N >> D >> T >> Z;
    int energy = T;
    int all_item = Z;
    int n_dan = D;
    int n_boss = N;

    int clear_boss = 0;

    vector<priority_queue<int, vector<int>, greater<int>>> item(all_item);

    while (n_dan--) {
        int cost,item_type;
        cin >> cost >> item_type;
        item[item_type].push(cost);
    }


    while (n_boss--) {
        int n_item_need;
        cin >> n_item_need;
        vector<int> need;

        while (n_item_need--) {
            int item_need;
            cin >> item_need;
            need.push_back(item_need);
        }

        bool can_kill = true;

        for(auto &x : need){
            if(item[x].empty()){
                can_kill = false;
                break;
            }

            int use_cost = item[x].top();
            item[x].pop();

            energy -= use_cost;

            if (energy < 0) {
                can_kill = false;
                break;
            }
        }

        if (!can_kill) {
            break;
        }
        clear_boss++;
    }
    
    cout << clear_boss;

}