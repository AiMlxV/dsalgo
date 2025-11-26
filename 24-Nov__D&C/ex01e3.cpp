    #include "bits/stdc++.h"
    #include <algorithm>
    #include <vector>

    using namespace std;

    int 
    main(){
        int n,m;
        vector<int> change_n;
        vector<int> data;
        cin >> n >> m;
        while (n--) {
            int intput;
            cin >> intput;
            change_n.push_back(intput);
        }
        for (int i = 0; i < m; i++) {
            int intput;
            cin >> intput;
            data.push_back(intput);
        }

        for (int i = 0; i < m; i++) {
            auto it = upper_bound(change_n.begin(),change_n.end(),data[i]);
            if (it == change_n.begin()) {
                data[i] = -1;
            }
            else{
                it--;
                data[i] = *it;
            }
        }

        for (auto &x: data) {
            cout << x << "\n";
        }
    }