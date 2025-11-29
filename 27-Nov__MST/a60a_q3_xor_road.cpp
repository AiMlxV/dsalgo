#include "bits/stdc++.h"
#include <utility>
#include <vector>

using namespace std;

vector<long long> p;

int find_set(int x){
    if (p[x] < 0) {
        return  x;
    }
    p[x] = find_set(p[x]);
    return p[x];
}

void union_set(int a, int b){
    int s1 = find_set(a);
    int s2 = find_set(b);

    if(s1 != s2){
        if (p[s1] > p[s2]) {
            swap(s1,s2);
        }

        p[s1] += p[s2];
        p[s2] = s1;
    }
}

int main(){
    long long n;
    cin >> n;
    vector<long long> vertex (n);
    
    vector<pair<long long, pair<long long, long long>>> edges;
    
    p.assign(n, -1);

    for (int i = 0; i < n; i++) {
        cin >> vertex[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int u = i;
            int v = j;
            int w = vertex[u]^vertex[v];

            edges.push_back({w,{u,v}});
        }
    }

    sort(edges.rbegin(),edges.rend());

    unsigned long long total_cost = 0;
    int edges_count = 0;

    for (auto &x : edges) {
        int w = x.first;
        int u = x.second.first;
        int v = x.second.second;

        if(find_set(u) != find_set(v)){
            union_set(u, v);
            total_cost+=w;
            edges_count++;
            if (edges_count == n-1) {
                break;
            }
        }
    }

    // for (auto &x : edges) {
    //     cout << x.first << ":" << x.second.first << "_" << x.second.second << endl;
    // }

    cout << total_cost << endl;
}