#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T>
void CP::queue<T>::merge_greater(CP::queue<T> &other) {
  if (this == &other) return;

  size_t new_cap = mSize + other.size();
  T *new_mData = new T[new_cap];
  size_t new_idx = 0;

  std::vector<T> new_b;
  new_b.reserve(other.size());

  size_t ori_b_size = other.size();

  for (size_t i = 0; i < ori_b_size; i++) {
    T val_a = mData[(mFront + i) % mCap];
    T val_b = other.mData[(other.mFront + i) % other.mCap];

    new_mData[new_idx++] = val_a;

    if (val_b > val_a) {
      new_mData[new_idx++] = val_b;
    } else {
      new_b.push_back(val_b);
    }
  }

  for (size_t i = ori_b_size; i < mSize; i++) {
    new_mData[new_idx++] = mData[(mFront + i) % mCap];
  }

  delete[] mData;       
  mData = new_mData;    
  mCap = new_cap;       
  mSize = new_idx;      
  mFront = 0;

  for (size_t i = 0; i < new_b.size(); i++) {
    other.mData[i] = new_b[i];
  }
  other.mSize = new_b.size();
  other.mFront = 0;
}

#endif