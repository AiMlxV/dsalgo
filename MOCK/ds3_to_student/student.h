#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "map_bst.h"
#include <cstddef>

// this is the modify() function to be submitted
template <typename KeyT, typename MappedT, typename CompareT>
void CP::map_bst<KeyT, MappedT, CompareT>::modify(
    CP::map_bst<KeyT, MappedT, CompareT> &other) {

  // your code here
  if (other.mRoot == NULL) {
    return;
  }

  if (mRoot == NULL) {
    mRoot = other.mRoot;
    mSize = other.mSize;
    other.mRoot = NULL;
    other.mSize = 0;
    return;
  }

  graft(mRoot, other.mRoot, other.mSize);

  other.mRoot = NULL;
  other.mSize = 0;

  return;
}

// you may use this function to find the grafting point
template <typename KeyT, typename MappedT, typename CompareT>
void CP::map_bst<KeyT, MappedT, CompareT>::graft(
    CP::map_bst<KeyT, MappedT, CompareT>::node *n,
    CP::map_bst<KeyT, MappedT, CompareT>::node *m, size_t otherSize) {

  // your code here
  if (mLess(m->data.first, n->data.first)) {
    if (n->left == NULL) {
      n->left = m;
      m->parent = n;
      mSize += otherSize;
    } else {
      graft(n->left, m, otherSize);
    }
  }

  else if (mLess(n->data.first, m->data.first)) {
    if (n->right == NULL) {
      n->right = m;
      m->parent = n;
      mSize += otherSize;
    } else {
      graft(n->right, m, otherSize);
    }
  }

  else {
    if (n->left == NULL && n->right == NULL) {
      node *p = n->parent;

      if (p == NULL) {
        mRoot = m;
      } else {
        if (p->left == n) {
          p->left = m;
        } else {
          p->right = m;
        }
      }

      m->parent = p;
      delete n;
      mSize += (otherSize - 1);
    }
  }

  return;
}

#endif
