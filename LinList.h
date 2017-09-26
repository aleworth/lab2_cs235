#ifndef L_L_
#define L_L_

using namespace std;

#include "LinkedListInterface.h"

class LinkList : public LinkedListInterface
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
