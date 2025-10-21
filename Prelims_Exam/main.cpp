#include "Array.h"

int main() {
    Array arr;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. RemoveAt\n";
        cout << "3. RotateRight\n";
        cout << "4. Sort Descending\n";
        cout << "5. Move Evens Right\n";
        cout << "6. Insert After\n";
        cout << "7. Delete All Less Than Index\n";
        cout << "8. Print Array\n";
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
            int k;
            cout << "Enter k: ";
            cin >> k;
            arr.rotateRight(k);
        }
        else if (choice == 4) {
            arr.sortArrayDesc();
        }
        else if (choice == 5) {
            arr.moveEvensRight();
        }
        else if (choice == 6) {
            int target, newVal;
            cout << "Enter target and value to insert after: ";
            cin >> target >> newVal;
            arr.insertAfter(target, newVal);
        }
        else if (choice == 7) {
            int idx;
            cout << "Enter index: ";
            cin >> idx;
            arr.deleteAllLessThanIndex(idx);
        }
        else if (choice == 8) {
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