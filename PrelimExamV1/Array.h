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

    // TODO: Insert value at the end of the array
    // Example: insert(10) -> [10]
    void insert(int value);

    // TODO: Remove element at given index
    // Example: [10,20,30], removeAt(1) -> [10,30]
    void removeAt(int index);

    // Print the current array elements
    void print() const;

    // TODO: Rotate array left by k positions
    // Example: [1,2,3,4,5], rotateLeft(2) -> [3,4,5,1,2]
    void rotateLeft(int k);

    // TODO: Sort array in ascending order using Bubble Sort
    // Example: [4,1,3,2] -> [1,2,3,4]
    void sortArrayAsc();

    // TODO: Move all odd numbers to the left, keep order
    // Example: [2,5,6,7] -> [5,7,2,6]
    void moveOddLeft();

    // TODO: Insert newValue before each occurrence of target
    // Example: [10,20,20,30], insertBefore(20,99) -> [10,99,20,99,20,30]
    void insertBefore(int target, int value);

    // TODO: Delete the element before each occurrence of target
    // Example: [10,5,5,20,30], deleteBefore(20) -> [10,5,20,30]
    void deleteBefore(int target);
};

#endif
