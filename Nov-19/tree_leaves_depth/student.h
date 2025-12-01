#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"
#include <cstddef>

template <typename KeyT, typename MappedT, typename CompareT>
long long CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, size_t aux) {
  // you may use this function
  int i = 0;
  
  if(n == NULL){
    return 0;
  }

  //count left subtree
  if (n->left!=NULL) {
    i+= my_recur(n->left, aux+1);
  }

  //count right subtree
  if (n->right!=NULL) {
    i+= my_recur(n->right, aux+1);
  }

  //can't count anymore
  if (n->left == NULL && n->right == NULL) {
    return aux;
  }

  return i;
}

template <typename KeyT, typename MappedT, typename CompareT>
long long CP::map_bst<KeyT, MappedT, CompareT>::sum_leaves_depth() {
  // write your code here
  return my_recur(mRoot, 0);
}

#endif
