#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
  //write your code here
  std::vector<T> tmp(mData[0],mData+(1<<k));

  std::sort(tmp.rbegin(),tmp.rend());

  return *(tmp.end()-k);
  //can include anything
}

#endif
