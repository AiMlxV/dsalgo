
#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "list.h"

template <typename T>
void CP::list<T>::zigzag(CP::list<T> &ls) {
    /*

        “In war, then, let your great object be victory, not lengthy campaigns.”
        ― Sun Tzu, The Art of War 

        ""
    */

    node *head_a = mHeader->next;
    node *head_b = ls.mHeader->next;
    node *before = ls.mHeader->prev;

    while ((head_b!=mHeader)&&(head_b!=ls.mHeader)) {
        node * new_head_b = head_a->next;

        head_a->next = head_b;
        head_b->prev = head_a;
        head_a = head_b;
        head_b = new_head_b;
    }

    ls.mHeader->next = ls.mHeader;
    ls.mHeader->prev = ls.mHeader;

    if (head_b == mHeader) {
        before->next = mHeader;
        mHeader->prev = before;
    }

    mSize+= ls.mSize;
    ls.mSize=0;

}

#endif
