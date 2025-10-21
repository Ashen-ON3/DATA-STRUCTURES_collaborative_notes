#include "Array.h"
#include <iostream>
using namespace std;

// Constructor
Array::Array(int capacity) {
    this->capacity = capacity;
    size = 0;
    data = new int[capacity];
}

// Destructor
Array::~Array() {
    delete[] data;
}

// Insert at the end (example already implemented)
void Array::insert(int value) {
    if (size == capacity) {
        cout << "Array is full!" << endl;
        return;
    }
    data[size++] = value;
}

// Remove at index
// TODO: Implement this function
// Description: Remove the element at the given index and shift
//              all elements to the left to fill the gap.
void Array::removeAt(int index) {
    // Your code here
    for(int i = index; i < size; i++)
    {
        int temp = data[i];
        data[i] = data[i + 1];
        data[i + 1] = temp;
    }
    size--;
}

// Remove given number of occurrences
// TODO: Implement this function
// Description: Remove up to 'count' occurrences of 'value'
//              starting from the left. Keep array compact.
void Array::removeOccurrences(int value, int count) {
    // Your code here
    if (count <= 0) 
    {
        return;
        
    }
    
    for (int i = 0; i < size && count > 0; ) 
    {
        if (data[i] == value) {
        removeAt(i);
        count--;
    } 
    else
    {
        i++;
    }
}
}

// Remove all occurrences
// TODO: Implement this function
// Description: Remove ALL occurrences of 'value' from the array.
void Array::removeAllOccurrences(int value) {
    // Your code here
    for(int i = 0; i < size; i++)
    {
       if(data[i] == value)
       {
           removeAt(i);
       }
    }
    
}

// Replace all occurrences
// TODO: Implement this function
// Description: Replace all instances of 'target' with 'newValue'.
void Array::replaceAllOccurrences(int target, int newValue) {
    // Your code here
    for(int i = 0; i < size; i++)
    {
        if(data[i] == target)
        {
            data[i] = newValue;
        }
    }
}

// Insert after each occurrence of target
// TODO: Implement this function
// Description: For every 'target' in the array, insert 'newValue'
//              right after it. Shift elements to make space.
void Array::insertAfter(int target, int newValue) {
    // Your code here
   int i = 0;
   while(i < size)
   {
       if(data[i] == target)
       {
           if(size == capacity)
           {
               return;
           }
           
           for(int j = size; j > i + 1; j--)
           {
               data[j] = data[j - 1];
           }
           
           data[i + 1] = newValue;
           size++;
           i += 2;
       }
       else
       {
           i++;
       }
   }
    
}

// Swap elements at indices
// TODO: Implement this function
// Description: Swap the values stored at index 'i' and 'j'.
void Array::swap(int i, int j) {
    // Your code here
    int temp = 0;
    temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

// Print array (already implemented for testing)
void Array::print() const {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << data[i];
        if (i < size - 1) cout << ", ";
    }
    cout << " ]" << endl;
}