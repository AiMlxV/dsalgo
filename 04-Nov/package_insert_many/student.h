#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  //write your code here
  for (size_t i = 0; i < data.size(); ++i) {
    int pos = data[i].first;
    T value = data[i].second;
    if (pos < 0){
      pos = 0;
    } 
    if ((size_t)pos > this->size()){
      pos = static_cast<int>(this->size());
    }
    insert(begin() + pos, value);
  }
}

#endif
