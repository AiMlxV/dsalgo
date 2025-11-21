#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <cstddef>
#include <iostream>

#include "queue.h"


template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {
  if (pos >= mSize or mSize <= 1 or pos == mSize - 1) {
    return;
  } //check
  size_t idx = (mFront + pos) % mCap;
  T tmp = mData[idx]; //data to move
  for (size_t i  = pos; i < mSize; ++i) {
    size_t from = (mFront + i + 1) % mCap;
    size_t to = (mFront + i) % mCap;
    mData[to] = mData[from]; //shift data
  }
  mData[(mFront+mSize-1)%mCap] = tmp; //insert data
}

#endif
