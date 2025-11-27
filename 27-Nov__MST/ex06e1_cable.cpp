#include "bits/stdc++.h"

using namespace std;

vector<int> p;

int find_set(int x){
    if (p[x] < 0) { 
        return x;
    }
    p[x] = find_set(p[x]);
    return p[x];
}

void dset_union(int a,int b){
    int s1 = find_set(a);
    int s2 = find_set(b);

    if (s1 != s2) {
        if (p[s1] > p[s2]) { 
            swap(s1,s2);
        }

        p[s1] += p[s2];
        p[s2] = s1;
    }
}


int main(){
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> edges;

    p.assign(n,-1);
    
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            int w;
            cin >> w;
            
            

            int u = i;
            int v = i + j + 1;
            edges.push_back({w,{u,v}});
        }
    }

    sort(edges.begin(),edges.end());

    long long total_cost = 0;

    for (auto &x : edges) {
        int w = x.first;
        int u = x.second.first;
        int v = x.second.second;

        if (find_set(u) != find_set(v)) {
            dset_union(u, v);
            total_cost += w;
        }
    }

    // for (auto &x : edges) {
    //     cout << x.first << ":" << x.second.first << "_" << x.second.second << endl;
    // }

    cout << total_cost << endl;
}