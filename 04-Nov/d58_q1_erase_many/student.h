#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <cstddef>

template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  //write your code here
  size_t offset = 0;
  for (auto &it : pos) {
      erase(begin()+it-offset);
      offset++;
  }
}

#endif
