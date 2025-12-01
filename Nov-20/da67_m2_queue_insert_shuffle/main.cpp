#include "queue.h"
#include "student.h"
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    CP::queue<int> q;
    int n, m, pos;
    std::cin >> n >> m >> pos;
    std::vector<int> items(m);
    for(int i=0;i<n;i++) {
        int x;
        std::cin >> x;
        q.push(x);
    }
    for (int &e : items) {
        std::cin >> e;
    }
    q.insert_shuffle(items, pos);
    q.print(); //print elements in queue

    return 0;
}