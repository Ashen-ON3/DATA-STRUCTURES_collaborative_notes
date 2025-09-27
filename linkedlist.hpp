#pragma once
#include "list.hpp"
#include "node.hpp"
#include <stdexcept>
#include <iostream>
#include <string>
class SinglyLinkedList : public List{
	node* head;
	node* tail;
	int size;

	public:
		SinglyLinkedList() {
			head = NULL;
			tail = NULL;
			size = 0;
		}

		void addLast(int elem) {
			node* n = new node;
			n->next = nullptr;
			n->elem = elem;
			if (tail) {
				tail->next = n;
			} else {
				head = n;
			}
			tail = n;
			++size;
		}

		void addFirst(int elem) {
		    node* n = new node;
			n->next = head;
			n->elem = elem;
			if (!head) {
				tail = n;
			}
			head = n;
			++size;
		}

		int removeLast() {
			if (!tail) {
				throw std::logic_error("Cannot remove from empty list");
			}
			int ret = tail->elem;
			if (tail == head) {
				tail = NULL;
				delete head;
				head = NULL;
			} else {
				node* curr = head;
				while (curr->next != tail) {
					curr = curr->next;
				}
				delete tail;
				tail = curr;
				tail->next = NULL;
			}
			size--;
			return ret;
		}

		int removeFirst() {
		    if (!head) {
				throw std::logic_error("Cannot remove from empty list");
			}
			int ret = head->elem;
			node* tmp =  head;
			head = head -> next;
			if(!head){
			    tail = NULL;
			}
			
			delete tmp;
			size--;
			
			return ret;
		}

		int get(int pos) {
		    
		    if(pos > size || pos <= 0)
		    {
		        throw std::logic_error("Invalid position: " + std::to_string(pos));
		    }
		    else
		    {
		        node* curr = head;
		        int index = 1;
		        while(curr != NULL)
		        {
		            if(index == pos)
		            {
		                return curr->elem;
		                
		            }
		            curr = curr->next;
		            index++;
		        }
		    }
		    
		}

		void remove(int elem) {
		    
			return;
		}

		int search(int elem) {

			return -1;
		}

		int getSize() {
			return size;
		}

		void print() {
			if (size == 0) {
				std::cout << "Empty";
			}
			for (node* curr = head; curr != nullptr; curr = curr->next) {
				std::cout << curr->elem;
				if (curr->next) {
					std::cout << " -> ";
				}
			}
			std::cout << std::endl;
		}
};
class DoublyLinkedList : public List {
	node* head;
	node* tail;
	int size;

public:
	DoublyLinkedList() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	void addLast(int elem) {
		node* n = new node;
		n->elem = elem;
		n->next = nullptr;
		n->prev = tail;
		if (tail) {
			tail->next = n;
		} else {
			head = n;
		}
		tail = n;
		size++;
	}

	void addFirst(int elem) {
		node* n = new node;
		n->elem = elem;
		n->next = head;
		n->prev = nullptr;
		if (head) {
			head->prev = n;
		} else {
			tail = n;
		}
		head = n;
		size++;
	}

	int removeLast() {
		if (!tail) {
			throw std::logic_error("Cannot remove from empty list");
		}
		int ret = tail->elem;
		node* tmp = tail;
		tail = tail->prev;
		if (tail) {
			tail->next = nullptr;
		} else {
			head = nullptr;
		}
		delete tmp;
		size--;
		return ret;
	}

	int removeFirst() {
		if (!head) {
			throw std::logic_error("Cannot remove from empty list");
		}
		int ret = head->elem;
		node* tmp = head;
		head = head->next;
		if (head) {
			head->prev = nullptr;
		} else {
			tail = nullptr;
		}
		delete tmp;
		size--;
		return ret;
	}

	int get(int pos) {
		if (pos > size || pos <= 0) {
			throw std::logic_error("Invalid position: " + std::to_string(pos));
		}
		node* curr = head;
		int index = 1;
		while (curr != nullptr) {
			if (index == pos) {
				return curr->elem;
			}
			curr = curr->next;
			index++;
		}
		return -1; // Should not reach
	}

	void print() {
		if (size == 0) {
			std::cout << "Empty";
		}
		for (node* curr = head; curr != nullptr; curr = curr->next) {
			std::cout << curr->elem;
			if (curr->next) {
				std::cout << " -> ";
			}
		}
		std::cout << std::endl;
	}
};