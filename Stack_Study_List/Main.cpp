#include "Stack.h"
#include <iostream>
using namespace std;

int main() {
    Stack st(20);  // fixed capacity stack for testing
    int choice;

    do {
        cout << "\nStack Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. IsEmpty\n";
        cout << "5. Size\n";
        cout << "6. Print\n";
        cout << "0. Quit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int val;
            cout << "Enter value to push: ";
            cin >> val;
            st.push(val);
        }
        else if (choice == 2) {
            st.pop();
        }
        else if (choice == 3) {
            cout << "Top element: " << st.top() << "\n";
        }
        else if (choice == 4) {
            cout << (st.isEmpty() ? "Stack is empty\n" : "Stack is not empty\n");
        }
        else if (choice == 5) {
            cout << "Stack size: " << st.size() << "\n";
        }
        else if (choice == 6) {
            st.print();
        }
        else if (choice == 0) {
            cout << "Exiting program...\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
