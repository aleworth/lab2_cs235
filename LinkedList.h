#ifndef L_L_
#define L_L_

#include <stdexcept>
#include "LinkedListInterface.h"

using namespace std;

template<typename T>

class LinkedList : public LinkedListInterface<T>
{
  public:
    LinkedList();
    ~LinkedList();

	bool find(T) {
		Node* temp = head;
		if (temp == NULL) {
			delete temp;
			return false;
		}
		while (temp != T) {
			temp = temp->next;
			if (temp == T) {
				delete temp;
				return true;
			}
			else if (temp == NULL) {
				delete temp;
				return false;
			}
		}
	}

	void insertHead(T) {

		bool check = LinkedList::find(T);
		if (check == true) {

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
		else {
			cout << "T is already in the current Linked List." << endl;
		}
    }

	void insertTail(T) {

		bool check = LinkedList::find(T);
		if (check == false) {
			if (head == NULL) {
				insertHead(T);
			}
			else if (head != NULL) {
				Node* gnu_pnt = new Node(T);
				gnu_pnt->next = NULL;
				Node* temp = head;
				bool test = true;
				while (test) {
					if (temp->next == NULL) {
						temp->next = gnu_pnt;
						delete temp;
						test = false;
					}
					temp = temp->next;
				}
			}
		}
		else {
			cout << "T is already in the current Linked List." << endl;
		}
	}

    void insertAfter(T value, T insertionNode) {
		bool check = LinkedList::find(value);
		bool recheck = LinkedList::find(insertionNode);
		if (recheck == true && check == false) {
			Node* temp = head;
			while (temp != insertionNode) {
				temp = temp->next;
			}
			Node* gnu_pnt2 = new Node(value);
			gnu_pnt2->next = temp->next;
			temp->next = gnu_pnt2;
		}
		else if (recheck == false) {
			cout << "insertionNode not found." << endl;
		}
		else if (check == true) {
			cout << "T is already in the current list." << endl;
		}

    }

    void remove(T) {
		bool check = LinkedList::find(T);
		if (check == true) {
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
		else {
			cout << "T is not in the current Linked List." << endl;
		}
    }

	void clear() {
		while (head != NULL) {
			LinkedList::remove(head);
		}
	}

	T at(int index) {
		int check = LinkedList::size();
		if (check < index) {
			throw out_of_range;
		}
		else {
			int i = 0;
			Node* temp5 = head;
			while (i != index) {
				temp5 = temp5->next;
				i++;
			}
			return temp5->data;
		}
	}

	int size() {
		int i = 0;
		if (head == NULL) {
			return i;
		}
		Node* temp4 = head;
		while (temp4 != NULL) {
			i++;
			temp4 = temp4->next;
		}
		delete temp4;
		return i;
	}

	string toString() {
		if (head == NULL) {
			string fail = "Failure!";
			return fail;
		}
		else {
			stringstream ss;
			Node* temp6 = head;
			while (temp6 != NULL) {
				if (temp6 == head) {
					ss += temp6->data;
					temp6 = temp6->next;
				}
				else {
					ss += " ";
					ss += temp6->data;
					temp6 = temp6->next;
				}
			}
			delete temp6;
			return ss;
		}
	}

  private:
      struct Node {
        T data;
        Node* next;
        Node(const T& data_item, Node* next_ptr = NULL) : data(data_item), next(next_ptr) {}
      }
      Node* head = NULL;

};
#endif
