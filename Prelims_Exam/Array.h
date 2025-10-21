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

    // Adds the given value to the end of the array.
    // Example: insert(10), insert(20) -> [10, 20]
    void insert(int value);

    // Removes the element at the given index, shifting remaining elements left.
    // Example: [10,20,30], removeAt(1) -> [10,30]
    void removeAt(int index);

    // Prints all elements in the array.
    // Example: [10,20,30]
    void print() const;

    // Rotates the array to the right by k positions.
    // Example: [1,2,3,4,5], rotateRight(2) -> [4,5,1,2,3]
    void rotateRight(int k);

    // Sorts the array in descending order using Bubble Sort.
    // Example: [4,1,3,2] -> [4,3,2,1]
    void sortArrayDesc();

    // Moves all even numbers to the right side while preserving order.
    // Example: [2,5,6,7] -> [5,7,2,6]
    void moveEvensRight();

    // Inserts the given value after each occurrence of target.
    // Example: [10,20,20,30], insertAfter(20,99) -> [10,20,99,20,99,30]
    void insertAfter(int target, int value);

    // Deletes all elements less than the value at the given index.
    // Example: [10,50,20,60,5], deleteAllLessThanIndex(1) -> [50,60]
    void deleteAllLessThanIndex(int index);
};

#endif