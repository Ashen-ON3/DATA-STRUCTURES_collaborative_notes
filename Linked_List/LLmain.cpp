#include <iostream>
#include <stdexcept>
#include "linkedlist.hpp"

using namespace std;

int main() {
	List* list;
	char op;
  	int num;
	cout << "Singly or Doubly? ";
	cin >> op;
	if (op == 'S' || op == 's') {
		list = new SinglyLinkedList();
	} else {
		list = new DoublyLinkedList();
	}
	do {
  	try {
	    cout << "Operation: ";
	    cin >> op;

	    switch (op) {
	      case 'l': // Insert Last
	        cin >> num;
	        list->addLast(num);
	        break;
	      case 'f': // Insert First
	        cin >> num;
	        list->addFirst(num);
	        break;
	      case 'L': // Remove Last
	        cout << list->removeLast() << endl;
	        break;
	      case 'F': // Remove First
	        cout << list->removeFirst() << endl;
	        break;

	      case 'g': // Get
	        cin >> num;
	        cout << list->get(num) << endl;
	        break;

	      case 'p':
	        list->print();
	        break;

	      case 'x':
	        cout << "Exiting";
	        break;

	      default:
	      	cout << "Invalid operation. Try again." << endl;
	    }
	} catch (exception& e) {
		cout << e.what() << endl;
	}
  } while (op != 'x');

  return 0;
}