#ifndef L_L_
#define L_L_

using namespace std;

#include "LinkedListInterface.h"

template<typename T>

class LinkedList : public LinkedListInterface (void)
{
  public:
    LinkedList();
    ~LinkedList();

    void insertHead(T value);
    void insertTail(T value);
    void insertAfter(T value, T insertionNode);
    void remove(T value);
    void clear();
    T at(int index);
    int size();
    string toString();

  private:
      struct Node {
        T value data;
        Node* next;

        Node(const T value& data_item, Node* next_ptr = Null) : data(data_item), next(next_ptr) {}
      }
      Node* head = NULL;

};
#endif
