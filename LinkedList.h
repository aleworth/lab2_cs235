#ifndef L_L_
#define L_L_

#include <stdexcept>
#include <sstream>
#include <cmath>
#include "LinkedListInterface.h"

using namespace std;

template<typename T>

class LinkedList : public LinkedListInterface<T>
{
  public:
    LinkedList() {};
    ~LinkedList() {};


	void insertHead(T value) {

		bool check = find(value);
		if (check == true) {

			if (head == NULL) {
				head = new Node(value);
				head->next = NULL;

			}
			else {
				Node* temp = new Node(value);
				temp->next = head;
				head = temp;
				delete temp;
			}
		}
		else {
			cout << "T is already in the current Linked List." << endl;
		}
  };

	void insertTail(T value) {

		bool check = find(value);
		if (check == false) {
			if (head == NULL) {
				insertHead(value);
			}
			else if (head != NULL) {
				Node* gnu_pnt = new Node(value);
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
	};

    void insertAfter(T value, T insertionNode) {
		bool check = find(value);
		bool recheck = find(insertionNode);
		if (recheck == true && check == false) {
			Node* temp = head;
			while (temp->data != insertionNode) {
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

  };

    void remove(T value) {
		bool check = find(value);
		if (check == true) {
			if (value == head->data) {
				Node* temp = head;
				head = head->next;
				delete temp;
			}
			else {
				Node* temp2 = head;
				while (temp2->next->data != value) {
					temp2 = temp2->next;
					if ((temp2->next == NULL) && (temp2->next->data != value)) {
						break;
					}
				}
				Node* temp3 = temp2->next;
				temp2 = temp3->next;
				delete temp3;
			}
		}
		else {
			cout << "Value is not in the current Linked List." << endl;
		}
  };

	void clear() {
		while (head != NULL) {
			remove(head->data);
		}
	};

	T at(int index) {
		int check = size();
		if (check < index) {
			throw out_of_range ("out_of_range");
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
	};

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
	};

	string toString() {
		if (head == NULL) {
			string fail = "Failure!";
			return fail;
		}
		else {
			stringstream ss;
      string answer;
			Node* temp6 = head;
			while (temp6 != NULL) {
				if (temp6 == head) {
					ss << temp6->data;
					temp6 = temp6->next;
				}
				else {
					ss << " ";
					ss << temp6->data;
					temp6 = temp6->next;
				}
			}
			delete temp6;
      ss >> answer;
			return answer;
		}
	};

  private:
      struct Node {
        T data;
        Node* next;
        Node(const T& data_item, Node* next_ptr = NULL) : data(data_item), next(next_ptr) {}
      };
      Node* head = NULL;

      bool find(T value) {
    		Node* temp = head;
    		if (temp == NULL) {
    			delete temp;
    			return false;
    		}
    		while (temp->data != value) {
    			temp = temp->next;
    			if (temp->data == value) {
    				delete temp;
    				return true;
    			}
    		}
    	};

};
#endif
