#include "bits/stdc++.h"
#include <queue>
#include <vector>

using namespace std;

int main(){
    priority_queue<int> item_line_up;
    int value, n;
    char ops_code;
    cin >> n;
    while (n--) {
        cin >> ops_code;
        if (ops_code == 'P') {
            cin >> value;
            item_line_up.push(value);
        }
        else if (ops_code == 'Q') {
            if (!item_line_up.empty()) {
                cout << item_line_up.top() << "\n";
                item_line_up.pop();
            }
            else {
                cout << "-1" << "\n";
            }
        }
    }
}