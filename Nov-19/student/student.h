#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>
#include "queue.h"

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
  // your code here
  std::sort(pos.begin(),pos.end()); //to reduece time
  int i = 0,j = 0,k = 0;
  while (i<mSize) {
    while (i == pos[k]) { //if found element that equal
      i++; k++;
    }
    mData[(mFront+j)%mCap] = mData[(mFront+i)%mCap]; //move element
    i++; j++;
  }
  mSize-=pos.size();
}

#endif
