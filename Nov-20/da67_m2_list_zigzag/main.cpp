#include <iostream>
#include "list.h"
#include "student.h"

using namespace std;

int main() {
    int n1,n2;
    cin>>n1;
    int t;
    CP::list<int> l1;
    CP::list<int> l2;
    for(int i = 0 ; i < n1 ; i++){
        cin>>t;
        l1.push_back(t);
    }
    cin>>n2;
    for(int i = 0 ; i < n2 ; i++){
        cin>>t;
        l2.push_back(t);
    }
    l1.zigzag(l2);
    l1.print();
    return 0;
}
