  #ifndef __STUDENT_H_
  #define __STUDENT_H_

  //you can include any other file here
  //you are allow to use any data structure
  #include "unordered_set"
  #include "vector.h"

  template <typename T>
  void CP::vector<T>::uniq() {
    //do someting here
    std::pmr::unordered_set<T> seen;
    size_t write = 0;
    for (size_t read = 0; read < mSize; ++read) {
      if (seen.insert(mData[read]).second) {
        if (write != read) mData[write] = mData[read];
        ++write;
      }
    }
    mSize = write;
  }
  
  #endif
