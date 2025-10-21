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
    Array(int capacity = 100);
    ~Array();

    void insert(int value);
    void removeAt(int index);
    void swap(int i, int j);
    void removeOccurrences(int value, int count);
    void removeAllOccurrences(int value);
    void replaceAllOccurrences(int target, int newValue);
    void insertAfter(int target, int newValue);
    void print() const;
};

#endif