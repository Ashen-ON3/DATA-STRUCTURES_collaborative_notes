#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

class Array {
private:
    int* data;
    int size;
    int capacity;

public:
    Array(int capacity = 100);  // default large capacity
    ~Array();

    void insert(int value);           // insert at end
    void removeAt(int index);         // remove at index
    int get(int index) const;         // get element
    int getSize() const;              // get size
    void print() const;               // print array
};

#endif
