#include <bits/stdc++.h>
#include "iomanip"
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    double W; int N;
    cin >> W >> N;

    vector<double> v(N);
    for(auto &x : v) cin >> x;
    double ans = 0;
    vector<pair<double, double>> items(N); //Ratio
    for(int i=0; i<N; i++) {
        double w; cin >> w;
        if (w == 0) {
            if (v[i] > 0) {
                 ans += v[i];
            }
        items[i] = {0, 0};
        } else {
            items[i] = {v[i]/w, w};
        }
    }
    sort(items.rbegin(), items.rend());
    for(auto x : items) {
        if(W <= 0) break;
        double take = min(W, x.second); 
        ans += take * x.first;
        W -= take;
    }

    cout << fixed << setprecision(4) << ans;
    return 0;
}
