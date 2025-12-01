    #include <cstddef>
void splitList(list<T>& list1, list<T>& list2) {
      // Add your code here

      //find  spitter position
      std::size_t spilter_pos;
      if (size()%2 == 0) {
        spilter_pos = size()/2;
      }
      else {
        spilter_pos = (size()/2)+1;
      }

      // go to spitter position
      auto it = begin();
      for(auto i = 0; i < spilter_pos; i++){
        ++it;
      }

      //list 1
      (list1.mHeader)->prev->next = mHeader->next;
      (list1.mHeader)->prev->next->prev = (list1.mHeader)->prev;
      (list1.mHeader)->prev = (it.ptr)->prev;
      (list1.mHeader)->prev->next = (list1.mHeader);
      list1.mSize = spilter_pos;

      //list 2
      (list2.mHeader)->prev->next = (it.ptr);
      (list2.mHeader)->prev->next->prev = (list2.mHeader)->prev;
      (list2.mHeader)->prev = (mHeader)->prev;
      (list2.mHeader)->prev->next = (list2.mHeader);
      list2.mSize = mSize - spilter_pos;

      mSize = 0;

      //curticular
      mHeader->next = mHeader;
      mHeader->prev = mHeader;
    }