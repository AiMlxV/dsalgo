#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"
#include <cstddef>


template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{
    size_t n_element = b - a;

    //expand
    if (mCap < mSize + n_element + 1) {
        expand(mCap*2);
    }

    //shift
    for (int i = 0; i < a; i++) {
        mData[mSize + n_element - i] = mData[mSize - i - 1];
    }

    //insert
    for (int i = 0; i <= n_element; i++) {
        mData[mSize+n_element - a -i*2] = mData[mSize-a-1-i];
        mData[mSize+n_element - a -i*2-1] = mData[mSize-a-1-i];
    }
    mSize+=n_element+1;
}

#endif