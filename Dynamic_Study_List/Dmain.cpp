#include "DArray.h"

int main() {
    Array arr;
    int choice;

    do {
        cout << "\nMenu (Dynamic Version):\n";
        cout << "1. Insert\n";
        cout << "2. RemoveAt\n";
        cout << "3. Print Array\n";
        cout << "0. Quit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int val;
            cout << "Enter value to insert: ";
            cin >> val;
            arr.insert(val);
        }
        else if (choice == 2) {
            int idx;
            cout << "Enter index to remove: ";
            cin >> idx;
            arr.removeAt(idx);
        }
        else if (choice == 3) {
            arr.print();
        }
        else if (choice == 0) {
            cout << "Quitting program...\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}