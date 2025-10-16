#include "DArray.h"

Array::Array(int capacity) {
    this->capacity = capacity;
    size = 0;
    data = (int*)malloc(capacity * sizeof(int)); // or data = (int*)realloc(data, capacity * sizeof(int));
    if (!data) {
        cerr << "Memory allocation failed!\n";
        exit(1);
    }
}

Array::~Array() {
    free(data);
}

// Expand when full
void Array::dynamic_add() {
    if(size == capacity)
    {
        capacity = capacity * 2;
        data = (int*) realloc(data, capacity*sizeof(int));
    }

}

// Shrink when too empty
void Array::dynamic_reduce() {
    if(size <= capacity / 4 && capacity > 4)
    {
        capacity /= 2;
        data = (int*) realloc(data, capacity*sizeof(int));
    }
    else if(capacity <= 4)
    {
        capacity = 4;
    }

}

// Insert at end with scaling
void Array::insert(int value) {
    dynamic_add();
    data[size++] = value;
}

// Remove at index with shrinking
void Array::removeAt(int index) {
    if(index < 0 || index > size)
    {
        return;
    }
    
    for(int i = index; i < size - 1; i++)
    {
        data[i] = data[i + 1];
    }
    size--;
    dynamic_reduce();
    

}

// Print array
void Array::print() const {
    cout << "[ ";
    for (int i = 0; i < capacity; i++) {
        if (i < size)
            cout << data[i];  // actual elements
        else
            cout << "#";      // unused slots
        if (i < capacity - 1) cout << ", ";
    }
    cout << " ]  Size: " << size << "  Capacity: " << capacity << "\n";
}