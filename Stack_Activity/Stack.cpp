#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack(int capacity) : arr(capacity) {}

void Stack::push(int value) {
    arr.insert(value);
}

void Stack::pop() {
    if(size() == 0)
    {
        cout << "Stack is empty. Cannot pop." << endl;
    }
    else
    {
        arr.removeAt(size());
    }
}

int Stack::top() const {
    if(size() == 0)
    {
        cout << "Stack is empty." << endl;
        return -1;
    }
    else
    {
        return arr.get(size() - 1);
    }
}

bool Stack::isEmpty() const {
    if(size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Stack::size() const {
    
    return arr.getSize();
}

void Stack::print() const {
    cout << "Stack (bottom → top): ";
    for (int i = 0; i < size(); i++) {
        cout << arr.get(i) << " ";
    }
    cout << "\n";
}