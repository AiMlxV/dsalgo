#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"
#include <cstddef>
template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  //write your code here
  mSize+=(last-first);
  T *n_arr = new T[mSize];
  //shift
  int i1 = 0;
  for (; i1 < position - begin(); i1++) {
    n_arr[i1] = mData[i1];
  }
  //insert
  int i2 = i1;
  for (auto j = first; j < last; j++) {
    n_arr[i1] = *j;
    i1++;
  }
  //insert remain
  for (; i1 < mSize; i1++) {
    n_arr[i1] = mData[i2];
    i2++;
  }
  delete [] mData;
  mData = n_arr;
  mCap = mSize;
}

#endif
