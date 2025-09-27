#include <iostream>
#include <vector>

class Deque {
private:
    std::vector<int> arr;
    int front, rear, size, capacity;

    void resize() {
        std::vector<int> new_arr(capacity * 2);
        for (int i = 0; i < size; i++) {
            new_arr[i] = arr[(front + i) % capacity];
        }
        arr = new_arr;
        front = 0;
        rear = size - 1;
        capacity *= 2;
    }

public:
    Deque(int cap) : capacity(cap), size(0), front(0), rear(cap - 1) {
        arr.resize(capacity);
    }

    // push() - equivalent to push_back for stack/queue/deque
    void push(int x) {
        push_back(x);
    }

    // pop() - equivalent to pop_back for stack/deque
    int pop() {
        return pop_back();
    }

    void push_back(int x) {
        if (size == capacity) resize();
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
    }

    void push_front(int x) {
        if (size == capacity) resize();
        front = (front - 1 + capacity) % capacity;
        arr[front] = x;
        size++;
    }

    int pop_back() {
        if (size == 0) return -1; // Error indicator
        int x = arr[rear];
        rear = (rear - 1 + capacity) % capacity;
        size--;
        return x;
    }

    int pop_front() {
        if (size == 0) return -1; // Error indicator
        int x = arr[front];
        front = (front + 1) % capacity;
        size--;
        return x;
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }
};

int main() {
    std::cout << "Dynamic Array Implementation using Deque" << std::endl;

    // Stack usage (LIFO)
    std::cout << "\nStack operations:" << std::endl;
    Deque stack(5);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    std::cout << "Pop: " << stack.pop() << std::endl; // 30
    std::cout << "Pop: " << stack.pop() << std::endl; // 20

    // Queue usage (FIFO)
    std::cout << "\nQueue operations:" << std::endl;
    Deque queue(5);
    queue.push(10);
    queue.push(20);
    queue.push(30);
    std::cout << "Dequeue: " << queue.pop_front() << std::endl; // 10
    std::cout << "Dequeue: " << queue.pop_front() << std::endl; // 20

    // Deque usage (double-ended)
    std::cout << "\nDeque operations:" << std::endl;
    Deque deque(5);
    deque.push_back(10);
    deque.push_front(5);
    deque.push_back(15);
    deque.push_front(1);
    std::cout << "Pop front: " << deque.pop_front() << std::endl; // 1
    std::cout << "Pop back: " << deque.pop_back() << std::endl;   // 15
    std::cout << "Pop front: " << deque.pop_front() << std::endl; // 5
    std::cout << "Pop back: " << deque.pop_back() << std::endl;   // 10

    return 0;
}