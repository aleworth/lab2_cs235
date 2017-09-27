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
    void remove(T vale);
    void clear();
    T at(int index);
    int size();
    string toString();

  private:

};
#endif
