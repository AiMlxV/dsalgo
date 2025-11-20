#include <stdexcept>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "map_bst.h"
#include "student.h"
using namespace std;
//#pragma once

int main() {
  CP::map_bst<string,int> tree1, tree2;
  int n, m;
  cin >> n >> m;
  for(int i=0;i<n;i++){ 
    string x;
    cin >> x;
		tree1.insert({x,1});
  }
  for(int i=0;i<m;i++){
    string x;
    cin >> x;
		tree2.insert({x,1});
  }
    
	tree1.modify(tree2);
  tree1.printResult();
    
	return 0;
}

