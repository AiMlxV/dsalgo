#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cstddef>
template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  //write your code here
  size_t pos = position - begin();
  size_t cnt = last - first;
  T *tmp = new T[cnt];
  for (size_t i = 0; i < cnt; ++i) {
    tmp[i] = *(first + i);
  }
  ensureCapacity(mSize + cnt);
  for (size_t i = mSize; i > pos; --i) {
    mData[i + cnt - 1] = mData[i - 1];
  }
  for (size_t i = 0; i < cnt; ++i) {
    mData[pos + i] = tmp[i];
  }

  mSize += cnt;
  delete [] tmp;
}

#endif
