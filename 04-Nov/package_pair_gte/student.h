#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "pair.h"

template <typename T1,typename T2>
bool CP::pair<T1,T2>::operator>=(const pair<T1,T2>& other) const {
  //write your code here
  return (((first > other.first) || (first == other.first && second > other.second)) || (first == other.first && second == other.second));

  return false;
}

#endif
