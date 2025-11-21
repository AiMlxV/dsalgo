#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace CP {

template <typename T>
class list
{
  protected:
    class node {
      friend class list;
      public:
        T data;
        node *prev;
        node *next;

        node() :
          data( T() ), prev( this ), next( this ) { }

        node(const T& data,node* prev, node* next) :
          data ( T(data) ), prev( prev ), next( next ) { }
    };

    class list_iterator {
      friend class list;
      protected:
        node* ptr;
      public:

        list_iterator() : ptr( NULL ) { }

        list_iterator(node *a) : ptr(a) { }

        list_iterator& operator++() {
          ptr = ptr->next;
          return (*this);
        }

        list_iterator& operator--() {
          ptr = ptr->prev;
          return (*this);
        }

        list_iterator operator++(int) {
          list_iterator tmp(*this);
          operator++();
          return tmp;

        }
        list_iterator operator--(int) {
          list_iterator tmp(*this);
          operator--();
          return tmp;
        }

        T& operator*() { return ptr->data; }
        T* operator->() { return &(ptr->data); }
        bool operator==(const list_iterator& other) { return other.ptr == ptr; }
        bool operator!=(const list_iterator& other) { return other.ptr != ptr; }
    };

  public:
    typedef list_iterator iterator;

  protected:
    node *mHeader; // pointer to a header node
    size_t mSize;


  public:
    //-------------- constructor & copy operator ----------

    // copy constructor
    list(list<T>& a) :
      mHeader( new node() ), mSize( 0 ) {
      for (iterator it = a.begin();it != a.end();it++) {
        push_back(*it);
      }
    }

    // default constructor
    list() :
      mHeader( new node() ), mSize( 0 ) { }

    // copy assignment operator using copy-and-swap idiom
    list<T>& operator=(list<T> other) {
      // other is copy-constructed which will be destruct at the end of this scope
      // we swap the content of this class to the other class and let it be descructed
      using std::swap;
      swap(this->mHeader, other.mHeader);
      swap(this->mSize, other.mSize);
      return *this;
    }

    ~list() {
      clear();
      delete mHeader;
    }

    //------------- capacity function -------------------
    bool empty() const {
      return mSize == 0;
    }

    size_t size() const {
      return mSize;
    }


    //----------------- iterator ---------------
    iterator begin() {
      return iterator(mHeader->next);
    }

    iterator end() {
      return iterator(mHeader);
    }
    //----------------- access -----------------
    T& front() { return mHeader->next->data; }

    T& back() { return mHeader->prev->data; }

    //----------------- modifier -------------
    void push_back(const T& element) {
      insert(end(),element);
    }

    void push_front(const T& element) {
      insert(begin(),element);
    }

    void pop_back() {
      erase(iterator(mHeader->prev));
    }

    void pop_front() {
      erase(begin());
    }

    iterator insert(iterator it,const T& element) {
      node *n = new node(element,it.ptr->prev, it.ptr);
      it.ptr->prev->next = n;
      it.ptr->prev = n;
      mSize++;
      return iterator(n);
    }

    iterator erase(iterator it) {
      iterator tmp(it.ptr->next);
      it.ptr->prev->next = it.ptr->next;
      it.ptr->next->prev = it.ptr->prev;
      delete it.ptr;
      mSize--;
      return tmp;
    }

    void clear() {
      while (mSize > 0) erase(begin());
    }

    void print() {
      std::cout << " Header address = " << (mHeader) << std::endl;
      int i;
      iterator before;
      for (iterator it = begin();it!=end();before = it, it++,i++) {
        std::cout << "Node " << i << ": " << *it;
        std::cout << " (prev = " << it.ptr->prev << ", I'm at " << it.ptr << ", next = " << it.ptr->next << ")" <<  std:: endl;
      }
    }

    void check() {
      node* p;
      int n;
      p = mHeader;
      n = mSize+1;
      while (n--) p = p->next;
      if (p != mHeader) {
        std::cout << "next POINTER ERROR" << std::endl;
      }
      p = mHeader;
      n = mSize+1;
      while (n--) p = p->prev;
      if (p != mHeader) {
        std::cout << "prev POINTER ERROR" << std::endl;
      }
    }

    void reorder(int pos, std::vector<int> selected) {
      if (selected.empty()) return;

      // 1. Find the insertion position
      // We do this first. Since the problem guarantees 'pos' is not inside 'selected',
      // this iterator will remain valid even after we erase other nodes.
      iterator insert_pos = begin();
      for (int i = 0; i < pos; i++) {
        insert_pos++;
      }

      // 2. Collect Data and Iterators
      // We use two pointers because 'selected' is sorted.
      // This allows us to do it in one pass O(N).
      std::vector<T> data_to_move;
      std::vector<iterator> iterators_to_erase;

      int current_idx = 0;
      auto list_it = begin();
      auto sel_it = selected.begin();

      while (list_it != end() && sel_it != selected.end()) {
        if (current_idx == *sel_it) {
            // Found a selected node! 
            // Save the DATA (T), not the pointer.
            data_to_move.push_back(*list_it);
            // Save the iterator to erase later.
            iterators_to_erase.push_back(list_it);
            
            sel_it++;
        }
        current_idx++;
        list_it++;
      }

      // 3. Erase old nodes
      // We must do this in a separate loop so we don't break the iterator 
      // used in the main scanning loop above.
      for (auto it : iterators_to_erase) {
        erase(it); // This deletes the memory!
      }

      // 4. Insert new nodes
      // insert_pos is still valid. We insert the data we saved.
      for (const auto& val : data_to_move) {
        insert(insert_pos, val);
      }
    }

};

}

//----------------------------------------------
int main() {
  int n;
  std::cin >> n;

  CP::list<std::string> l;
  int pos;
  std::vector<int> selected;

  while(n--) {
    std::string st;
    std::cin >> st;
    l.push_back(st);
  }

  std::cin >> n;
  while(n--) {
    int a;
    std::cin >> a;
    selected.push_back(a);
  }
  std::sort(selected.begin(),selected.end());

  //call student function
  std::cin >> pos;
  l.reorder(pos,selected);

  //check result
  l.check();
  auto it = l.begin();
  while (it != l.end()) {
    std::cout << *it << " ";
    it++;
  }
  std::cout << std::endl;
  it = l.end(); it--;
  while (it != l.end()) {
    std::cout << *it << " ";
    it--;
  }
  std::cout << std::endl;

}

