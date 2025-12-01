void replace(const T &x, list<T> &y) {
  // write your code here
  auto it = begin();
  while (it != end()) {
    if (*(it) == x) {
      it = erase(it);
      for (auto &element : y) {
        insert(it, element);
      }
    }
    else {
      ++it;
    }
  }
}