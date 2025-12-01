#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T>
void CP::queue<T>::insert_shuffle(std::vector<T> items, size_t pos)
{
	// write your code here
	if (items.empty()) {
		return;
	}

	T *tmp = new T[mSize+items.size()];

	int idx = 0;

	for (int i = 0; i < pos; i++) {
		tmp[idx] = mData[(mFront+i)%mCap];
		idx++;
	}

	int queue_idx = pos;
	int items_idx = 0;

	while ((queue_idx < mSize) &&(items_idx < items.size())) {
		
		//item
		tmp[idx] = items[items_idx];
		idx++;
		items_idx++;

		//queue
		tmp[idx] = mData[(mFront+queue_idx)%mCap];
		idx++;
		queue_idx++;

	}

	//if still have data remain in queue
	while (queue_idx < mSize) {
		tmp[idx] = mData[(mFront+queue_idx)%mCap];
		idx++;
		queue_idx++;
	}

	//if still have data remain in items
	while (items_idx < items.size()) {
		tmp[idx] = items[items_idx];
		idx++;
		items_idx++;
	}

	delete [] mData;
	mData = tmp;
	mSize = idx;
	mCap = mSize+items.size();
	mFront = 0;

}

#endif
