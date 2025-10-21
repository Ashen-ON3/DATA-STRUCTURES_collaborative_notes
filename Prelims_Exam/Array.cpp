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
    // TODO: Add the value at the end of the array
    data[size++] = value;
}

void Array::removeAt(int index) {
    // TODO: Remove element at the given index and shift remaining left
    int temp = 0;
    for(int i = index; i < size; i++)
    {
        temp = data[i];
        data[i] = data[i + 1];
        data[i + 1] = temp;
    }
    size--;
}

void Array::print() const {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << data[i];
        if (i < size - 1) cout << ", ";
    }
    cout << " ]" << endl;
}

void Array::rotateRight(int k) 
{
    if (size == 0) return;  // nothing to rotate
    k = k % size;           // handle k > size

    // Step 1: Reverse the whole array
    for (int i = 0, j = size - 1; i < j; i++, j--) {
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    // Step 2: Reverse the first k elements
    for (int i = 0, j = k - 1; i < j; i++, j--) {
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    // Step 3: Reverse the remaining elements
    for (int i = k, j = size - 1; i < j; i++, j--) {
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
}

void Array::sortArrayDesc() {
    // TODO: Sort the array in descending order
    for(int i = 0; i <= size - 1; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            if(data[j] < data[j + 1])
            {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    
}

void Array::moveEvensRight() {
    // TODO: Move even numbers to the right side while preserving order
    int* temp = new int[size];
    int pos = 0;

    // Add odds first
    for (int i = 0; i < size; i++) {
        if (data[i] % 2 != 0) {
            temp[pos++] = data[i];
        }
    }

    // Add evens next
    for (int i = 0; i < size; i++) {
        if (data[i] % 2 == 0) {
            temp[pos++] = data[i];
        }
    }

    // Copy back into original array
    for (int i = 0; i < size; i++) {
        data[i] = temp[i];
    }

    delete[] temp;
}

void Array::insertAfter(int target, int value) {
    // TODO: Insert the value after each occurrence of the target
    for(int i = 0; i < size; i++)
    {
        if(data[i] == target)
        {
            for(int j = size; j > i + 1; j--)
            {
                data[j] = data[j - 1];
            }
            data[i + 1] = value;
            size++;
            i++;
        }
    }
    
}

void Array::deleteAllLessThanIndex(int index) {
    // TODO: Delete all elements with value less than the value at given index
    int pos = 0;
    for(int i = 0; i < size ; ++i)
    {
        if(data[i] >= data[index])
        {
            data[pos++] = data[i];
        }
    }
    size = pos;
}