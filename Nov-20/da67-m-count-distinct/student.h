#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"
#include <unordered_set>

template <typename T>
size_t CP::vector<T>::count_distinct(CP::vector<T>::iterator a, CP::vector<T>::iterator b)
{
    // Write your code here
    std::unordered_set<T> result(a,b);
    return result.size();
}

#endif