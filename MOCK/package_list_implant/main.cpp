#include <iostream>
#include "list.h"
#include "student.h"
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    int t,pos1,pos2,count;
    CP::list<int> l1;
    CP::list<int> l2;
    for(int i=0;i<A;i++){
        cin >> t;
        l1.push_back(t);
    }
    for(int i=0;i<B;i++){
        cin >> t;
        l2.push_back(t);
    }
    cin >> pos1 >> pos2 >> count;
    l1.implant(l2,pos1,pos2,count);
    l1.print();
}
