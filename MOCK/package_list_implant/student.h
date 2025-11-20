#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "list.h"
template <typename T>
void CP::list<T>::implant(CP::list<T> &other, int pos1, int pos2, int count) {
  // Edit here.
  if (count == 0) {
    return;
  }

  auto it1 = begin();
  for (int i = 0; i < pos1; i++) {
    it1++;
  }

  node *p1 = it1.ptr;
  node *p1_next = p1->next;

  auto it2 = other.begin();
  for (int i = 0; i < pos2; i++) {
    it2++;
  }

  node *p2_begin = it2.ptr;

  for (int i = 0; i < count-1; i++) {
    it2++;
  }

  node *p2_end = it2.ptr;

  node *before_p1 = p2_begin->prev;
  node *after_p1 = p2_end->next;

  before_p1 -> next = after_p1;
  after_p1 -> prev = before_p1;

  other.mSize -= count;

  p1->next = p2_begin;
  p2_begin->prev = p1;

  p2_end->next = p1_next;
  p1_next->prev = p2_end;

  mSize += count;
}
#endif