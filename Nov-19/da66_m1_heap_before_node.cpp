#include "iostream"
#include <vector>

using namespace std;

int main(){
    vector<int> result;
    int n,m;
    cin >> n >> m;
    if (m == 0) {
        cout << "0";
    }
    else{
        for(int i = 0; i < n; i++){
        int j = i;
        while (j != m and j != 0){
            j = (j-1)/2;
        }
        if (j == m) {
            continue;
        }
        else{
            result.push_back(i);
        }
    }

    cout << result.size() << "\n";
    for (auto &x : result) {
        cout << x << " ";
    }
    }
    
}