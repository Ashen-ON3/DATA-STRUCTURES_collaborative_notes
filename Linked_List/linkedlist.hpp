#include "list.hpp"
#include "node.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;
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
				throw logic_error("Cannot remove from empty list");
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
		    if (!tail) {
				throw logic_error("Cannot remove from empty list");
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
		        throw logic_error("Invalid position: " + to_string(pos));
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
		    
		    node*curr=head;
            node* prev = nullptr;
            
            while (curr){
                if(curr->elem== elem){
                    if(curr==head){
                        head=head->next;
                    }else{
                        prev->next=curr->next;
                    }
                    if (curr==tail){
                        tail=prev;
                    }
                    delete curr;
                    size--;
                    return;
                }
                prev=curr;
                curr=curr->next;
            }
		}

		int search(int elem) {
		    
		    node* curr = head;
		    int index = 0;
		    
		    while (curr){
		        if(curr->elem == elem){
		            return index;
		        }
		        
		        curr = curr->next;
		        index++;
		    }
			return -1;
		}

		int getSize() {
			return size;
		}

		// int get(int index) {
		// 	if (index < 0 || index >= size) {
		// 		throw logic_error("Index out of bounds");
		// 		return -1;
		// 	}
			
		// 	node* curr = head;
		// 	for (int i = 0; i < index; i++) {
		// 		curr = curr->next;
		// 	}
		// 	return curr->elem;
		// }

		void print() {
			if (size == 0) {
				cout << "Empty";
			}
			for (node* curr = head; curr != nullptr; curr = curr->next) {
				cout << curr->elem;
				if (curr->next) {
					cout << " -> ";
				}
			}
			cout << endl;
		}
};