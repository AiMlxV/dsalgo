#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cstddef>
template <typename T>
void CP::vector<T>::compress() {
    //write your code here
    if (mSize == mCap) {
        return;
    }
    T *newarr = new T[mSize];
    for (size_t i = 0; i < mSize; i++) {
        newarr[i] = mData[i];
    }
    delete [] mData;
    mData = newarr;
    mCap = mSize;
}

#endif
