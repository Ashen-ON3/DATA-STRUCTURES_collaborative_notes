#include "Array.h"

Array::Array(int capacity) {
    this->capacity = capacity;
    size = 0;
    data = new int[capacity];
}

Array::~Array() {
    delete[] data;
}

// DONE
void Array::insert(int value) {
    data[size] = value;
    size++;
}

// DONE
void Array::removeAt(int index) {
    // Example: [10,20,30], removeAt(1) -> [10,30]
    for(int i = 0;i < size;i++){
        if(i == index){
            for(int j = index; j < size;j++){
              data[i] = data[i + 1];  
            } 
        }
    }
    size--;
}

// Print array elements
void Array::print() const {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << data[i];
        if (i < size - 1) cout << ", ";
    }
    cout << " ]" << endl;
}

// DONE
void Array::rotateLeft(int k) {
    // Example: [1,2,3,4,5], rotateLeft(2) -> [3,4,5,1,2]
    
    for(int i = 0;i < k;i++){
        int start = data[0];
        for(int j = 0;j < size ;j++){
         data[j] = data[j + 1];
        }
        data[size - 1] = start;
    }
}

// DONE
void Array::sortArrayAsc() {
    // Example: [4,1,3,2] -> [1,2,3,4]
    for(int i = 0;i < size; i++){
        for(int j = 0; j < size; j++){
            if(data[i] < data [j] && data[i] != data[j]){
                int temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
    

}

//DONE
void Array::moveOddLeft() {
    for(int i = 0; i < size - 1;i++){
        if(data[i]%2 == 0){
         for(int j = i;j < size; j++){
            int temp = data[j];
            data[j] = data[j + 1];
            data[j + 1] = temp;
         }
      }
    }
    
}

// DONE
void Array::insertBefore(int target, int value) {
    // Example: [10,20,20,30], insertBefore(20,99) -> [10,99,20,99,20,30]
    for(int i = 0; i < size; i++){
        if(data[i] == target){
            
            for(int j = size; j > i ;j--){
                data[j] = data[j - 1];
            }
            data[i] = value;
            size++;
            i++;
        
    }
 }
}

// DONE
void Array::deleteBefore(int target) {
    // Example: [10,5,5,20,30], deleteBefore(20) -> [10,5,20,30]
    for(int i = 0;i < size;i++){
        if(data[i] == target){
            for(int j = i - 1;j < size;j++){
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    size--;
    
    
}
