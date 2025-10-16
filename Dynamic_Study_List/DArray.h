#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cstdlib>  // for malloc, realloc, free
using namespace std;

class Array {
private:
    int* data;
    int size;
    int capacity;

    void dynamic_add();    // Expand capacity
    void dynamic_reduce(); // Shrink capacity if too empty

public:
    Array(int capacity = 4);
    ~Array();

    void insert(int value);
    void removeAt(int index);
    void print() const;
};

#endif