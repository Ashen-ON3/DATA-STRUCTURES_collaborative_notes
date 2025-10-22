#ifndef STACK_H
#define STACK_H

#include "Array.h"

class Stack {
private:
    Array arr; // use fixed-size array

public:
    Stack(int capacity = 100);

    void push(int value);
    void pop();
    int top() const;
    bool isEmpty() const;
    int size() const;
    void print() const;
};

#endif