#ifndef L_L_
#define L_L_

using namespace std;

#include "LinkedListInterface.h"

template<typename T>

class LinkedList : public LinkedListInterface<T>
{
  public:
    LinkedList();
    ~LinkedList();

    void insertHead(T) {
      if (head == NULL) {
        head = new Node(T);
        head->next = NULL;

      }
      else {
        Node* temp = new Node(T);
        temp->next = head;
        head = temp;
        delete temp;
      }
    }

    void insertTail(T) {
      if (head == NULL) {
        insertHead(T);
      }
      else if (head != NULL) {
        Node* new_pnt = new Node(T);
        new_pnt->next = NULL;
        Node* temp = head;
        bool test = true;
        while (test) {
          if (temp->next == NULL) {
            temp->next = new_pnt;
            delete temp;
            test = false;
        }
        temp = temp->next;
      }
      }
    }

    void insertAfter(T) {

    }

    void remove(T) {
      if (T = head) {
        Node* temp = head;
        head = head->next;
        delete temp;
      }
      else if (T->next = NULL) {

      }
      else {
        Node* temp2 = head;
        while (temp2->next->data != T) {
            temp2 = temp2->next;
            if ((temp2->next == NULL) && (temp2->next->data != T)) {
              break;
            }
        }
        Node* temp3 = temp2->next;
        temp2 = temp3->next;
        delete temp3;
      }
    }
    void clear();
    T at(int index);
    int size();
    string toString();

  private:
      struct Node {
        T data;
        Node* next;
        Node(const T& data_item, Node* next_ptr = Null) : data(data_item), next(next_ptr) {}
      }
      Node* head = NULL;

};
#endif
