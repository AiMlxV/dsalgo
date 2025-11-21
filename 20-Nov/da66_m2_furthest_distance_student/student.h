#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"
#include <algorithm>
#include <cstddef>

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, int &aux){
	// You MAY use this function
    if (n == NULL) {
        return 0;
    }

    int l_len = my_recur(n->left, aux);
    int r_len = my_recur(n->right, aux);

    aux = std::max(aux,l_len+r_len);

    return std::max(l_len,r_len)+1;
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance() {
	// write your code here

    if (empty()) {
        return -1;
    }

    int val = 0;
    my_recur(mRoot,val);
    return val;
}

#endif
