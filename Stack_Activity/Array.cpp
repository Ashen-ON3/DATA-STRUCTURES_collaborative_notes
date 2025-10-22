#include "Array.h"

Array::Array(int capacity) {
    this->capacity = capacity;
    size = 0;
    data = new int[capacity];
}

Array::~Array() {
    delete[] data;
}

void Array::insert(int value) {
    if(size == capacity)
    {
        cout << "Array is full. Cannot insert.";
    }
    else
    {
        data[size++] = value;
    }
}

void Array::removeAt(int index) {
    int temp = 0;
    if(index > size || index < 0)
    {
        return;
    }
    else
    {
        for(int i = index; i < size; i++)
        {
            temp = data[i];
            data[i] = data[i + 1];
            data[i + 1] = temp;
            
        }
        size--;
        
    }
    
}

int Array::get(int index) const {
    if(index > size || index < 0)
    {
        cout << "Invalid index." << endl;
        return -1;
    }
    else
    {
        return data[index];
    }

}

int Array::getSize() const {
    
    return size;
}

void Array::print() const {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << data[i];
        if (i < size - 1) cout << ", ";
    }
    cout << " ] Size: " << size << " / Capacity: " << capacity << "\n";
}