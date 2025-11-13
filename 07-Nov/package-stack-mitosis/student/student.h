#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"


template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{
    size_t a_element = mSize - 1 - static_cast<size_t>(a);
    size_t b_element = mSize - 1 - static_cast<size_t>(b);
    size_t len = static_cast<size_t>(b - a + 1);
    size_t newSize = mSize + len;

    if (mCap == 0) {
        expand(1);
    }
    while (mCap < newSize) {
        expand(mCap*2);
    }
    
    size_t r = static_cast<int>(mSize) - 1;
    size_t w = static_cast<int>(newSize) - 1;

    while (r > static_cast<int>(a_element)) {
        mData[w--] = mData[r--];
    }

    for (int i = static_cast<int>(a_element); i >= static_cast<int>(b_element); --i){
        T value = mData[i];
        mData[w--] = value;
        mData[w--] = value;
    }

    mSize = newSize;
}

#endif